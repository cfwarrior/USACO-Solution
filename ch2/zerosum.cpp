/*
ID: codefor3
TASK: zerosum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int eval(string& s, int res = 0, int term = 0, int sign = 1) {
    for(auto& c : s) {
        if(c == ' ') continue;
        if(isdigit(c)) {
            term = term*10+c-'0';
        }
        else {
            res += term * sign;
            term = 0; sign = 1;
            if(c == '-') {
                sign = -1;
            }
        }
    }
    return res + term * sign;
}
// order : space , + , -
void dfs(int k, string path, int n) {
    if(k > n) {
        if(eval(path) == 0) {
            fout << path << endl;
        }
        return;
    }
    dfs(k+1, path + ' ' + to_string(k), n);
    dfs(k+1, path + '+' + to_string(k), n);
    dfs(k+1, path + '-' + to_string(k), n);
}

int main() {
    int n;
    fin >> n;
    dfs(2, "1", n);
    return 0;
}