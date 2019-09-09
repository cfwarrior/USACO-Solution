/*
ID: codefor3
TASK: ratios
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
const int MAXN = 100001;
const int MOD = 1e9 + 7;
// parameter
ifstream fin ("ratios.in");
ofstream fout ("ratios.out");
int t[4][3];

int check(int sum[3]) {
    for(int i = 0; i < 3; ++i) {
        if(t[0][i] && sum[i]%t[0][i] != 0)
            return 0;
        int  ratio = 0;
        if(t[0][0] != 0) ratio = sum[0]/t[0][0];
        else if(t[0][1] != 0) ratio = sum[1]/t[0][1];
        else if(t[0][2] != 0) ratio = sum[2]/t[0][2];
        if(t[0][1] * ratio != sum[1] || t[0][2] * ratio != sum[2])
            return 0;
        return ratio;
    }
}
void read() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 3; ++j) {
            fin >> t[i][j];
        }
    }
}

void solve() {
    
    int k[3] = {};
    for(k[0] = 0; k[0] < 100; ++k[0]) {
        for(k[1] = 0; k[1] < 100; ++k[1]) {
            for(k[2] = 0; k[2] < 100; ++k[2]) {
                int sum[3] = {};
                for(int i = 1; i < 4; ++i) {
                    for(int j = 0; j < 3; ++j) {
                        sum[j] += t[i][j]*k[i-1];
                    }
                }
                int c = check(sum);
                if(c) {
                    fout << k[0] << " " << k[1] << " " << k[2] << " " << c << endl;
                    return ;
                }
            }
        }
    }
    fout << "NONE" << endl;
}

int main() {
    read();
    solve();
    return 0;
}