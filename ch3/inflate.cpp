/*
ID: codefor3
TASK: inflate
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
// complete Knapsack 
int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    int V, N;
    fin >> V >> N;
    int cost[N];
    int val[N];
    for(int i = 0; i < N; ++i)
        fin >> val[i] >> cost[i];
    int dp[V+1] = {};
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = cost[i]; j <= V; ++j) {
            dp[j] = max(dp[j], dp[j-cost[i]] + val[i]);
            ans = max(ans, dp[j]);
        }
    }
    fout << ans << endl;
    return 0;
}