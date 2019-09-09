/*
ID: codefor3
TASK: butter
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
int n;
const int MOD = 1e9 + 7;
// parameter
ifstream fin ("butter.in");
ofstream fout ("butter.out");
const int MAXN = 1451;
const int INF = 1e8;
int N, E, C;
int cows[2001];
int u[MAXN];
int v[MAXN];
int cost[MAXN];
vector<vector<int>> g(MAXN, vector<int>(MAXN, INF));
// floyd algorithm N^3 TLE
void read() {
    // pasture, path, cow
    fin >> C >> N >> E;
    for(int i = 1; i <= C; ++i)
        fin >> cows[i];
    for(int i = 0; i < E; ++i) {
        fin >> u[i] >> v[i] >> cost[i];
        // g[u[i]][v[i]] = g[v[i]][u[i]] = cost[i];
    }
    // for(int i = 1; i <= N; ++i)
    //     g[i][i] = 0;
}

int bellman_ford(int s) {
    vector<int> d(N+1, INF);
    d[s] = 0;
    while(true) {
        bool update = false;
        for(int i = 0; i < E; ++i) {
            if(d[u[i]] != INF && d[v[i]] > d[u[i]] + cost[i] ) {
                d[v[i]] = d[u[i]] + cost[i];
                update = true;
            }
            if(d[v[i]] != INF && d[u[i]] > d[v[i]] + cost[i] ) {
                d[u[i]] = d[v[i]] + cost[i];
                update = true;
            }
        }
        if(!update)
            break;
    }
    int total = 0;
    for(int i = 1; i <= C; ++i) {
        total += d[cows[i]];
    }
    return total;
}
void solve() {
    int minn = INF;
    for(int p = 1; p <= N; ++p) {
        minn = min(minn, bellman_ford(p));
    }
    fout << minn << endl;

}

int main() {
    read();
    solve();
    return 0;
}