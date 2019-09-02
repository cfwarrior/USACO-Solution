/*
ID: codefor3
TASK: dualpal
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool ispal(string& s) {
    int l = 0, r = s.size()-1;
    while(l < r) {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
} 

bool baseB(int n, int base) {
    string res;
    while(n > 0) {
        int d = n%base;
        n /= base;
        if(d <= 9) {
            res += d + '0';
        }
        else {
            res += (d-10) + 'A';
        }
    }
    return ispal(res);
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n, s;
    fin >> n >> s;
    ++s;
    
    for(; n > 0; ++s) {
        int count = 0;
        for(int base = 2; base <= 10; ++base) {
            if(baseB(s, base))
                ++count;
        }
        if(count >= 2) {
            fout << s << endl;
            --n;
        }
    }
    return 0;
}