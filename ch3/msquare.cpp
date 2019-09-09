/*
ID: codefor3
TASK: msquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
int n;
const int MAXN = 100001;
const int MOD = 1e9 + 7;
// parameter
ifstream fin ("msquare.in");
ofstream fout ("msquare.out");
string v = "12345678";
void read() {
    for(int i = 0; i < 8; ++i)
        fin >> v[i];
    reverse(v.begin()+4, v.end());
}
string transformA(string s) {
    for(int i = 0; i < 4; ++i)
        swap(s[i], s[i+4]);
    return s;    
}
string transformB(string s) {
    auto tmp = s[3];
    for(int i = 3; i > 0; --i)
        s[i] = s[i-1];
    s[0] = tmp;
    tmp = s[7];
    for(int i = 7; i > 4; --i)
        s[i] = s[i-1];
    s[4] = tmp;
    return s;
}

string transformC(string s) {
    auto tmp = s[5];
    s[5] = s[6];
    s[6] = s[2];
    s[2] = s[1];
    s[1] = tmp;
    return s;
}
void solve() {
    // state, transform
    queue<pair<string,string>> q;
    unordered_set<string> visited;
    string tmp;
    q.push({"12348765", ""});
    visited.insert("12348765");
    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; ++i) {
            string cur = q.front().first;
            // fout << cur << endl;
            string transform = q.front().second;
            if(cur == v) {
                fout << transform.size() << endl;
                fout << transform << endl;
                return;
            }
            q.pop();
            tmp = transformA(cur);
            // fout << "transformA from " << cur << " "<< tmp <<endl;
            if(visited.find(tmp) == visited.end()) {
                q.push({tmp, transform+'A'});
                visited.insert(tmp);
            }
            tmp = transformB(cur);
            // fout << "transformB from " << cur << " "<< tmp <<endl;
            if(visited.find(tmp) == visited.end()) {
                q.push({tmp, transform+'B'});
                visited.insert(tmp);
            }
            tmp = transformC(cur);
            // fout << "transformC from " << cur << " "<< tmp <<endl;
            if(visited.find(tmp) == visited.end()) {
                q.push({tmp, transform+'C'});
                visited.insert(tmp);
            }
        }

    }

}

int main() {
    read();
    solve();
    return 0;
}