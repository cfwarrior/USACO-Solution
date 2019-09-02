/*
ID: codefor3
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    vector<pair<int,int>> v;
    int a, b;
    for(int i = 0; i < n; ++i) {
        fin >> a >> b;
        v.push_back({a,b});
    }
    sort(begin(v), end(v));
    int start = v[0].first, end = v[0].second;
    int busy = end - start, idle = 0;
    for(int i = 1; i < n; ++i) {
        // idle time
        if(end < v[i].first) {
            idle = max(idle, v[i].first-end);
            start = v[i].first;
            end = v[i].second;
        }
        else {
            end = max(end, v[i].second);
            busy = max(busy, end-start);
        }
    }
    fout << busy << " " << idle << endl;
    return 0;
}