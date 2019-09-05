/*
ID: codefor3
TASK: nocows
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int dp[201][101] = {};
int mod = 9901;
int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int N, K;
    fin >> N >> K;

    if(N%2 == 0) {
        fout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= K; ++i) {
        for(int j = 1; j <= N; j+=2) {
            // left tree size
            if(j == 1) dp[j][i] = 1;
            for(int k = 1; k <= j-2; k+=2) {
                dp[j][i] = (dp[j][i] + dp[k][i-1] * dp[j-1-k][i-1])%mod;
            }
        }
    }

    int ans = (dp[N][K] - dp[N][K-1]+mod) % mod;
    fout << ans << endl;
    return 0;
}