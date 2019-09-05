/*
ID: codefor3
TASK: runround
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
int maxn = 3628800;

void dfs(int cur, int k, vector<bool>& used, vector<int>& candidate) {
     if(k == 0) {
         candidate.push_back(cur);
         return;
     }
     for(int i = 1; i <= 9; ++i) {
         if(!used[i]) {
             used[i] = true;
             dfs(cur*10+i, k-1, used, candidate);
             used[i] = false;
         }
     }
}
// check if runround number
bool check (int n) {
    string num = to_string(n);
    int sz = num.size();
    vector<bool> visited(sz);
    int pos = 0;
    for(int i = 0; i < sz; ++i) {
        pos = ((num[pos] - '0') + pos)%sz;
        if(visited[pos]) {
            return false;
        }
        visited[pos] = true;
    }
    return true;
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    int M;
    fin >> M;
    int k = to_string(M).size();
    vector<int> unique;
    vector<bool> used(10);
    // generate numbers with unique digits
    for(; k <= 9; ++k) {
        dfs(0, k, used, unique);
    }
    auto it = upper_bound(unique.begin(), unique.end(), M);
    int cur = -1;
    for(; it != unique.end(); ++it) {
        cur = *it;
        if(check(cur)) {
            fout << cur << endl;
            return 0;
        }
    }
    return 0;
}