/*
ID: codefor3
TASK: stamps
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>


using namespace std;
const int MAX = 2000001;
const int INF = 1000;
vector<int> dp(MAX, INF);

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    int K, N, maxv = 0;
    fin >> K >> N;
    vector<int> v(N);
    for(int i = 0; i < N; ++i) {
        fin >> v[i];
        maxv = max(maxv, v[i]);
    }
    int maxV = min(maxv*K, MAX);
    dp[0] = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = v[i]; j <= maxV; ++j) {
            dp[j] = min(dp[j], dp[j-v[i]]+1);
        }
    }
    int m = 1;
    for(; m <= maxV; ++m) {
        if(dp[m] > K)
            break;
    }
    fout << m-1 << endl;
    return 0;
}