/*
ID: codefor3
TASK: concom
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

double share[101][101] = {};
double sum[101] = {};
bool visited[101] = {};

void dfs(int i) {
    if(visited[i])
        return;
    visited[i] = 1;
    for(int j = 1; j <= 101; ++j) {
        sum[j] += share[i][j];
        if(sum[j] > 50) {
            dfs(j);
        }
    }
}
int main() {
    ofstream fout ("concom.out");
    ifstream fin ("concom.in");
    memset(share, 0, sizeof(share));
    int n;
    fin >> n;
    int i, j, p;
    while(n-- > 0) {
        fin >> i >> j >> p;
        share[i][j] = p;
    }

    for(int i = 1; i < 101; ++i) {
        memset(sum, 0, sizeof(sum));
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for(int j = 1; j < 101; ++j) {
            if(sum[j] > 50 && i != j) {
                fout << i << " " << j << endl;
            }
        }
    }
    return 0;
}