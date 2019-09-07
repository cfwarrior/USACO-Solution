/*
ID: codefor3
TASK: contact
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
#include <unordered_map>


using namespace std;

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    int A, B, N;
    fin >> A >> B >> N;
    string s, tmp;
    while(fin >> tmp) {
        s += tmp;
        if(tmp.size() < 80)
            break;
    }
    unordered_map<string,int> m;
    for(int w = A; w <= B; ++w) {
        for(int i = 0; i+w <= s.size(); ++i) {
            m[s.substr(i, w)]++;
        }
    }
    vector<pair<int,string>> stats;
    unordered_map<int, vector<string>> t;
    for(auto&[p, c] : m) {
        t[c].push_back(p);
    }
    vector<int> f;
    auto cmp = [] (const string& s1, const string& s2) {
        return s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2);
    };
    for(auto& [c, v] : t) {
        sort(t[c].begin(), t[c].end(), cmp);
        f.push_back(c);
    }
    sort(f.begin(), f.end(), greater<>());
    for(int i = 0; i < min(N, (int)t.size()); ++i) {
        fout << f[i] << endl;
        for(int k = 0; k < t[f[i]].size(); ++k) {
            if(k%6 == 0) {
                fout << t[f[i]][k];
            }
            else {
                fout << " " << t[f[i]][k];
            }
            if(k%6 == 5 || k == t[f[i]].size()-1)
                fout << endl;
        }
    }
    return 0;
}