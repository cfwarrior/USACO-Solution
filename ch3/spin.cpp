/*
ID: codefor3
TASK: spin
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
ifstream fin ("spin.in");
ofstream fout ("spin.out");

struct {
    int speed;
    int cnt;
    vector<pair<int,int>> wedges;
} wheels [5];

void read() {
    int speed, cnt , s, e;
    for(int i = 0; i < 5; ++i) {
        fin >> wheels[i].speed >> wheels[i].cnt;
        for(int k = 0; k < wheels[i].cnt; ++k) {
            fin >> s >> e;
            wheels[i].wedges.push_back({s, (s+e)%360});
        }
    }
}

bool check() {
    for(int d = 0; d <= 359; ++d) {
        int p = 0;
        for(int i = 0; i < 5; ++i) {
            // light pass one of the wedges
            for(auto& v : wheels[i].wedges) {
                if(
                (v.first <= v.second && (d >= v.first && d <= v.second)) ||
                (v.first > v.second) && (d >= v.first || d <= v.second)) {
                    ++p;
                    break;
                }
            }
        }
        if(p == 5) {
            return true;
        }
        
    }
    return false;
}
void spin() {
    for(auto& w : wheels) {
        for(auto& v : w.wedges) {
            v.first = (v.first + w.speed) % 360;
            v.second = (v.second + w.speed) % 360;
        }
    }
}
void solve() {
    bool flag = false;
    int i = 0;
    for(; i < 360; ++i) {
        if(check()) {
            flag = true;
            break;
        }
        spin();
    }
    if(flag) {
        fout << i << endl;
    }
    else {
        fout << "none" << endl;
    }
}



int main() {
    read();
    solve();
    return 0;
}