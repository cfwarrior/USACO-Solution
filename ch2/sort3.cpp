/*
ID: codefor3
TASK: sort3
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// 1. swap two number directly
// 2. 3-way trade
using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int t[4][4] = {};
    int n;
    fin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    int u, v;
    for(int i = 0; i < n; ++i) {
        u = a[i], v = sorted[i];
        if(u != v)
            t[u][v]++;
    }
    int ans = 0;
    int tmp = min(t[1][2], t[2][1]);
    ans += tmp;
    t[1][2] -= tmp; t[2][1] -= tmp;
    tmp = min(t[2][3], t[3][2]);
    ans += tmp;
    t[3][2] -= tmp; t[2][3] -= tmp;
    tmp = min(t[1][3], t[3][1]);
    ans += tmp;
    t[3][1] -= tmp; t[1][3] -= tmp;
    tmp = 0;
    for(int i = 1; i < 4; ++i) {
        for(int j = 1; j < 4; ++j) {
            tmp += t[i][j];
        }
    }
    ans += tmp/3*2;
    fout << ans << endl;
    return 0;
}