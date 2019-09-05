/*
ID: codefor3
TASK: prefix
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    vector<string> roots;
    string p;
    while(fin >> p) {
        if(p == ".") break;
        roots.push_back(p);
    }
    string s; 
    while(fin >> p) {
        if(p == "") break;
        s += p;
    }
    bool dp[200001] = {};
    dp[0] = 1;
    int n = s.size(), m = roots.size(), ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < m; ++j) {
            int len = roots[j].size();
            if(i >= len && dp[i-len] && 
                (s.substr(i-len, len) == roots[j])) {
                dp[i] = true;
                ans = i;
                continue;
            }
        }
    }
    fout << ans << endl;
    return 0;
}