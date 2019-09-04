/*
ID: codefor3
TASK: frac1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>



using namespace std;

int gcd(int a, int b) {
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int n;
    fin >> n;
    set<pair<int,int>> fset;
    fset.insert({0,1});
    fset.insert({1,1});
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            int d = gcd(i, j);
            fset.insert({j/d, i/d});
        }
    }
    vector<pair<int,int>> fracs(fset.begin(), fset.end());
    auto cmp = [] (pair<int,int>& p1, pair<int,int>& p2) {
        return p1.first * p2.second < p1.second * p2.first;
    };
    sort(fracs.begin(), fracs.end(), cmp);
    for(auto& f : fracs) {
        fout << f.first << "/" << f.second << endl;
    }
    return 0;
}