/*
ID: codefor3
TASK: comehome
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Floyd-Warshall algorithm
using namespace std;

int N = 52;
const int INF = 2e8;
vector<vector<int>> d(N, vector<int>(N, INF));
ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

int id(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return 26+c-'A';
}

void print(vector<vector<int>>& d) {
    for(auto& row : d) {
        for(auto c : row) {
            fout << c << " ";
        }
        fout << endl;
    }
    fout << endl;
}

int main() {

    int P, dist;
    char u, v;
    fin >> P;
    for(int i = 0; i < P; ++i) {
        fin >> u >> v >> dist;
        d[id(u)][id(v)] = d[id(v)][id(u)] 
        = min(d[id(u)][id(v)], dist);
    }
    // print(d);
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                   d[i][j] = d[i][k] + d[k][j]; 
                }
            }
        }
    }
    // print(d);
    int src = id('Z');
    int ans = INF;
    char cow = '.';
    for(char c = 'A'; c <= 'Y'; ++c) {
        if(d[src][id(c)] < ans) {
            ans = d[src][id(c)];
            cow = c;
        }
    }
    fout << cow << " " << ans << endl;
    return 0;
}