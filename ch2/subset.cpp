/*
ID: codefor3
TASK: subset
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
#include <map>


using namespace std;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int n;
    fin >> n;
    int total = n*(n+1)/2;
    if(total%2) {
        fout << 0 << endl;
        return 0;
    }
    int target = total/2;
    long long dp[target+1] = {};
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = target; j >= i; --j) {
            dp[j] += dp[j-i];
        }
    }
    fout << dp[target]/2 << endl;
    return 0;
}