/*
ID: codefor3
TASK: money
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    int V, N;
    fin >> V >> N;
    long long dp[N+1] = {};
    long long coins[V];
    for(int i = 0; i < V; ++i)
        fin >> coins[i];
    dp[0] = 1;
    for(int j = 0; j < V; ++j) {
        for(int i = 0; i <= N; ++i) {
            if(i >= coins[j]) {
                dp[i] += dp[i-coins[j]];
            }
        }
    }
    fout << dp[N] << endl;
    return 0;
}