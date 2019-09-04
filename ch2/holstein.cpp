/*
ID: codefor3
TASK: holstein
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

int V, G;

bool check(vector<int>& v) {
    for(auto i : v) {
        if(i > 0) {
            return false;
        }
    }
    return true;
}
bool dfs(vector<vector<int>>& g, vector<int>& path, int start, int K, vector<int>& v) {
    if(G-start + path.size() < K)
        return false;
    if(path.size() >= K) {
        return check(v);
    }
    for(int i = start; i < G; ++i) {
        // choose type i
        path.push_back(i);
        for(int j = 0; j < V; ++j) {
            v[j] -= g[i][j];
        }
        if(dfs(g, path, i+1, K, v))
            return true;
        path.pop_back();
        for(int j = 0; j < V; ++j) {
            v[j] += g[i][j];
        }
    }
    return false;
}
int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");

    fin >> V;
    vector<int> v(V);
    for(int i = 0; i < V; ++i)
        fin >> v[i];
    fin >> G;
    vector<vector<int>> g(G, vector<int>(V, 0));
    for(int i = 0; i < G; ++i) {
        for(int j = 0; j < V; ++j) {
            fin >> g[i][j];
        }
    }
    vector<int> path;
    for(int k = 1; k <= G; ++k) {
        if(dfs(g, path, 0, k, v)) {
            
            fout << path.size();
            for(auto i : path) {
                fout << " " << i+1;
            }
            fout << endl;
            return 0;
        }
    }
    return 0;
}