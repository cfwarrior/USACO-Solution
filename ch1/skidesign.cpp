/*
ID: codefor3
TASK: skidesign
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
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n;
    fin >> n;
    vector<int> hills(n);
    for(int i = 0; i < n ; ++i) {
        fin >> hills[i];
    }
    sort(hills.begin(), hills.end());
    int min_cost = 1e9;
    for(int low = hills[0]; low+17 <= hills.back(); ++low) {
        int high = low + 17;
        // cout << low << " " << high << endl;
        int cost = 0;
        for(int i = 0; hills[i] < low; i++) {
            cost += (hills[i] - low) * (hills[i] - low);
        }
        for(int i = hills.size()-1; hills[i] > high; --i) {
            cost += (hills[i] - high) * (hills[i] - high);
        }
        min_cost = min(min_cost, cost);
    }
    fout << min_cost << endl;

    return 0;
}