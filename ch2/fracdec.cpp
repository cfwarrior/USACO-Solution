/*
ID: codefor3
TASK: fracdec
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");
unordered_map<int,int> m;
// global parameter
int n, d;
string ans;
void read() {
    fin >> n >> d;
}

void solve() {
    ans += to_string(n/d);
    n -= (n/d) * d;
    if(n == 0) {
        ans += ".0";
        return;
    }
    ans += '.';
    m[n] = ans.size();
    while(n > 0) {
        n *= 10;
        int tmp = n/d;
        n -= d*tmp;
        ans += to_string(tmp);
        if(m.find(n) == m.end()) {
            m[n] = ans.size();
        }
        else {
            ans.insert(m[n], "(");
            ans += ")";
            return;
        }
    }

}

int main() {
    read();
    solve();
    for(int i = 0; i < ans.size(); ++i) {
        fout << ans[i];
        if(i%76 == 75 || i == ans.size()-1)
            fout << endl;
    }
    return 0;
}