/*
ID: codefor3
TASK: barn1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue> 

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m, s, c;
    fin >> m >> s >> c;
    vector<int> cows(c);
    for(int i = 0; i < c; ++i) {
        fin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    int total = cows.back() - cows[0]+1;
    priority_queue<int> pq;
    int diff = 0;
    for(int i = 1; i < c; ++i) {
        pq.push(cows[i] - cows[i-1] - 1);
    }
    for(int i = 1; i < m && !pq.empty(); ++i) {
        total -= pq.top();
        pq.pop();
    }
    fout << total << endl;
    return 0;
}