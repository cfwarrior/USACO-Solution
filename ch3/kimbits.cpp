/*
ID: codefor3
TASK: kimbits
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
const int MAXN = 100001;
const int MOD = 1e9 + 7;
// parameter
ifstream fin ("kimbits.in");
ofstream fout ("kimbits.out");
long long N, K, index;
void read() {
    fin >> N >> K >> index;
}
int dp[101][101];
// dp[i][j] number of length i , at most j '1'
// dp[i][j] = dp[i-1][j] + dp[i-1][i-1];
void solve() {
    for(int i = 0; i <= N; ++i) {
        dp[i][0] = dp[0][i] = 1;
    }
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    string res;
    for(int i = N-1; i >= 0; --i) {
        if(index > dp[i][K]) {
            res += '1';
            index -= dp[i][K];
            --K;
        }
        else {
            res += '0';
        }
    }
    fout << res << endl;
}

int main() {
    read();
    solve();
    return 0;
}