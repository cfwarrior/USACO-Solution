/*
ID: codefor3
TASK: milk
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
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    fin >> n >> m;
    int cost = 0;
    vector<pair<int,int>> farmer;
    int p , a;
    for(int i = 0; i < m; ++i) {
        fin >> p >> a;
        farmer.push_back({p, a});
    }
    sort(begin(farmer), end(farmer));
    for(int i = 0; i < m && n > 0; ++i) {
        int buy = min(n, farmer[i].second);
        cost += buy * farmer[i].first;
        n -= buy;
    }
    fout << cost << endl;
    return 0;
}