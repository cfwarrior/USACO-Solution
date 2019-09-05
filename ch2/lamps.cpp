/*
ID: codefor3
TASK: lamps
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
int b1 = 0b111111;
int b2 = 0b101010;
int b3 = 0b010101;
int b4 = 0b100100;

void dfs(int cur, int c, set<int>& state) {
    if(c == 0) {
        state.insert(cur);
        cout << cur << endl;
        return;
    }
    dfs(cur^b1, c-1, state);
    dfs(cur^b2, c-1, state);
    dfs(cur^b3, c-1, state);
    dfs(cur^b4, c-1, state);
}

bool valid (int state, vector<int>& on, vector<int>& off) {
    cout << "check state " << state << endl;
    for(int i = 0; i < 6; ++i) {
        if(on[i] && !(state&(1<<(5-i)))) {
            return false;
        }
        if(off[i] && (state&(1<<(5-i)))) {
            return false;
        }
    }
    return true;
}

string expand(int state, int N) {
    string base;
    for(int i = 0; i < 6; ++i) {
        base = to_string(state%2) + base;
        state /= 2;
    }
    string res;
    while(N >= 6) {
        res += base;
        N -= 6;
    }
    res += string(base.begin(), base.begin()+N);
    return res;
}

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    int N, C;
    fin >> N >> C;
    vector<int> on(6);
    vector<int> off(6);
    int tmp;
    while(fin >> tmp) {
        if(tmp == -1)
            break;
        on[(tmp-1)%6] = true;
    }

    while(fin >> tmp) {
        if(tmp == -1) break;
        off[(tmp-1)%6] = true;
    }
    for(int i = 0; i < 6; ++i) {
        if(on[i] && off[i]) {
            fout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    // button one has cycle length 1
    // button 2 and 3 has cycle length 2
    // button 4 has cycle length 3
    // so button i == button i+6
    // press a button = x ^ b
    int cur = 0b111111;
    set<int> state;
    while(C > 4) {
        C -= 2; // press two button = 0
    }
    dfs(cur, C, state);
    bool impossible = true;
    for(auto& st : state) {
        cout << st << endl;
        // valid
        if(valid(st, on, off)) {
            fout << expand(st, N) << endl;
            impossible = false;
        }
    }
    if(impossible) {
        fout << "IMPOSSIBLE" << endl;
    }
    return 0;
}