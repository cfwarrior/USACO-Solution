/*
ID: codefor3
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("beads.in", "r" ,stdin);
    freopen("beads.out", "w", stdout);
    string s;
    int n;
    cin >> n >> s;
    s += s;
    vector<int> t;  // transition point, record of end index of last segment
    int mx = -1;
    int last = -1;
    t.push_back(last);
    char cur = '.';
    for(int i = 0; i < 2*n; ++i) {
        if(s[i] == 'w')
            continue;
        if(cur == '.') {
            cur = s[i];
            last = i;
        }
        else {
            // the start of a new segment
            if(cur != s[i]) {
                int len = t.size() < 2 ? i : i- t[t.size()-2]-1;
                mx = max(mx, len);
                t.push_back(last);
            }
            cur = s[i];
            last = i;
        }
    }
    mx = (mx == -1 || mx >= n) ? n : mx;
    cout << mx << endl;
    return 0;
}