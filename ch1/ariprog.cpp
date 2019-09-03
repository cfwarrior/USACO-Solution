/*
ID: codefor3
TASK: ariprog
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;
// TLE without lookup table, unordered_set is slow
bool lookup[250*250*2+1];

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    // clock_t t1,t2;
    // t1 = clock();  
    int n, m;
    fin >> n >> m;
    int limit = m*m*2;
    unordered_set<int> uset;
    for(int p = 0; p <= m; ++p) {
        for(int q = 0; q <= m; ++q) {
            uset.insert(p*p+q*q);
        }
    }
    for(auto i : uset)
        lookup[i] = true;
    vector<int> v (uset.begin(), uset.end());
    sort(v.begin(), v.end());
    vector<pair<int,int>> res;
    int sz = v.size();
    int a, b;
    for(int i = 0; i < sz; ++i) {
        a = v[i];
        for(int j = i+1; j < sz; ++j) {
            b = v[j] - a;
            // early break;
            if(n-1*b + a > limit)
                break;
            int k = 2, cur = v[j] + b;
            while(cur <= limit && lookup[cur]) {
                cur += b;
                ++k;
                if(k == n) {
                    break;
                }
            }
            if(k == n) {
                res.push_back({b, a});
            }
        }
    }
    sort(res.begin(), res.end());
    if(res.size() == 0) {
        fout << "NONE" << endl;
    }
    else {
        for(auto& p : res) {
            fout << p.second << " " << p.first << endl;
        }
    }
    // t2 = clock();
    // cout << ((float) t2 - t1 ) /  CLOCKS_PER_SEC << endl;
    return 0;
}