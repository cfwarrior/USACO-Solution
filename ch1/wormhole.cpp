/*
ID: codefor3
TASK: wormhole
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
int x[15], y[15], next_right[15];
int n;
int ans =  0;

int cycle() {

    int i, j, k;
    for(i = 1; i <= n; ++i) {
        k = x[i];
        // move n step, if not at 0 then cycle
        for(j = 1; j <= n; ++j) {
            k = next_right[k];
            k = x[k];
        }
        if(k)
            return 1;        
    }
    return 0;
}

void dfs(int k, int i) {
    if(k > n) {
        ans += cycle();
        return;
    }
    // find first unmatched
    for(; i <= n; ++i) {
        if(!x[i])
            break;
    }
    int j = i+1;
    for(; j <= n; ++j) {
        if(!x[j]) {
            x[i] = j; x[j] = i;
            dfs(k+2, i+1);  // i+1 ?
            x[i] = x[j] = 0;
        }
    }
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin >> n;
    x[0] = 2e9;
    // build graph
    for(int i = 1; i <= n; ++i) {
        fin >> x[i] >> y[i];
        for(int j = 1; j < i; ++j) {
            if(y[i] != y[j]) continue;
            // i is on the right of j
            if(x[i] > x[j]) {
                if(x[i] < x[next_right[j]]) {
                    next_right[j] = i;
                }
            }
            // j is on the right of i
            else {
                if(x[j] < x[next_right[i]]) {
                    next_right[i] = j;
                }
            }
        }
    }
    // 
    memset(x, 0, sizeof(x));
    dfs(1,1);
    fout << ans << endl;

    return 0;
}