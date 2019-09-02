/*
ID: codefor3
TASK: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

string baseB(int n, int base) {
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
    reverse(res.begin(), res.end());
    return res;
}

bool ispal(string& s) {
    int l = 0, r = s.size()-1;
    while(l < r) {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
} 

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;

    for(int i = 1; i <= 300; ++i) {
        string square = baseB(i*i, base);
        if(ispal(square)) {
            fout << baseB(i, base) << " " << square << endl;
        }
    }
    return 0;
}