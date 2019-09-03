/*
ID: codefor3
TASK: numtri
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
int ans = 0;

// TODO: using two rows
int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int n;
    fin >> n;
    vector<vector<int>> nums(n);
    for(int i = 0; i < n; ++i) {
        nums[i].resize(i+1);
        for(int j = 0; j < i+1; ++j) {
            fin >> nums[i][j];
        }
    }
    for(int i = n-2; i >= 0; --i) {
        for(int j = 0; j < i+1; ++j) {
            nums[i][j] += max(nums[i+1][j], nums[i+1][j+1]);
        }
    }
    fout << nums[0][0] << endl;
    return 0;
}