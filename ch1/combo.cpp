/*
ID: codefor3
TASK: combo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool close(vector<int>& p, vector<int>& q, int n) {
    for(int i = 0; i < 3; ++i) {
        int dif = abs(p[i] - q[i]);
        if(dif <= 2 || dif >= n-2) 
            continue;
        else
            return false;
    }
    return true;
}
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n;
    vector<int> p1(3);
    vector<int> p2(3);
    fin >> n;
    fin >> p1[0] >> p1[1] >> p1[2];
    fin >> p2[0] >> p2[1] >> p2[2];
    int count = 0;
    for(int a = 1; a <= n; a++) {
        for(int b = 1; b <= n; b++) { 
            for(int c = 1; c <= n; c++) {
                vector<int> p = {a, b, c};
                if(close(p, p1, n) || close(p, p2, n)) {
                    ++count;
                }
            }
        }
    }
    fout << count << endl;
    return 0;
}