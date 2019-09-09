/*
ID: codefor3
TASK: fact4
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
int n;
const int MAXN = 100001;
const int MOD = 1e9 + 7;
// parameter
ifstream fin ("fact4.in");
ofstream fout ("fact4.out");

void read() {
    fin >> n;
}
void solve() {
    int digit = 1;
    int n2 = 0, n5 = 0;
    for(int i = 2; i <= n; ++i) {
        int j = i;
        while(j%2 == 0) {
            ++n2;
            j /= 2;
        }
        while(j%5 == 0) {
            ++n5;
            j /= 5;
        }
        digit = (digit*j) % 10;
    }
    for(int i = 0; i < n2-n5; ++i) {
        digit = (digit*2)%10;
    }
    fout << to_string(digit) << endl;
}

int main() {
    read();
    solve();
    return 0;
}