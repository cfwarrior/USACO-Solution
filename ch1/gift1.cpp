/*
ID: codefor3
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    unordered_map<string, int> mp;
    fin >> n;
    vector<string> names(n);
    for(int i = 0; i < n; ++i) {
        fin >> names[i];
        mp[names[i]] = 0;
    }
    
    string giver, taker;
    int ng, total, left;
    while(fin >> giver) {
        fin >> total >> ng;
        if(ng == 0)
            continue;
        int delta = total/ng;
        left = total - delta * ng;
        mp[giver] -= (total-left);
        for(int k = 0; k < ng; ++k) {
            fin >> taker;
            mp[taker] += delta;
        }
    }

    for(int i = 0; i < n; ++i) {
        fout << names[i] <<  " " << mp[names[i]] << endl;
    }
    return 0;
}