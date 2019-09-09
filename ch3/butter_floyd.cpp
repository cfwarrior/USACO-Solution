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
int N, P, C;
int cows[2001];
int u[MAXN];
int v[MAXN];
int cost[MAXN];
vector<vector<int>> g(MAXN, vector<int>(MAXN, INF));
// floyd algorithm N^3 TLE
void read() {
    // pasture, path, cow
    fin >> C >> N >> P;
    for(int i = 1; i <= C; ++i)
        fin >> cows[i];
    for(int i = 0; i < P; ++i) {
        fin >> u[i] >> v[i] >> cost[i];
        g[u[i]][v[i]] = g[v[i]][u[i]] = cost[i];
    }
    for(int i = 1; i <= N; ++i)
        g[i][i] = 0;
}

void solve() {
    // floyd
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
            }
        }
    }
    // for(int i = 1; i <= N; ++i) {
    //     for(int j = 1; j <= N; ++j) {
    //         fout << g[i][j] << " ";
    //     }
    //     fout << endl;
    // }

    long long minn = 1e11;
    for(int p = 1; p <= N; ++p) {
        long long sum = 0;
        for(int c = 1; c <= C; ++c) {
            sum += g[p][cows[c]];
        }
        minn = min(sum, minn);
    }
    fout << minn << endl;

}

int main() {
    read();
    solve();
    return 0;
}