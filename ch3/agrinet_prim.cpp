/*
ID: codefor3
TASK: agrinet
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
int g[101][101] = {};
const int INF = 1e9;
int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> g[i][j];

    vector<int> min_cost (n, INF);
    vector<bool> used(n, false);
    min_cost[0] = 0;
    int total = 0;

    while(true) {
        //closest node
        int v = -1;
        for(int u = 0; u < n; ++u) {
            if(!used[u] && (v == -1 ||  min_cost[u] < min_cost[v])) {
                v = u;
            }
        }
        if(v == -1) break;

        used[v] = true;
        total += min_cost[v];
        for(int u = 0; u < n; ++u) {
            min_cost[u] = min(min_cost[u], g[u][v]);
        }
    }
    fout << total << endl;
    return 0;
}