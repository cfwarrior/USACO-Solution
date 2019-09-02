/*
ID: codefor3
TASK: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int t[10] = {};
// good digit
bool good[10] = {};

bool valid(int prod, int limit) {
    if(prod >= limit) return false;
    while(prod > 0) {
        if(!good[prod%10]) return false;
        prod /= 10;
    }
    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i) {
        fin >> t[i];
        good[t[i]] = true;
    }
    int a, b, c, d, e;
    int count = 0;
    for(int i1 = 0; i1 < n; ++i1) {
        a = t[i1];
        for(int i2 = 0; i2 < n; ++i2) {
            b = t[i2];
            for(int i3 = 0; i3 < n; ++i3) {
                c = t[i3];
                int abc = a*100+b*10+c;
                for(int i4 = 0; i4 < n; ++i4) { 
                    d = t[i4];
                    int prod1 = abc*d;
                    if(!valid(prod1, 1000))
                        continue;
                    for(int i5 = 0; i5 < n; ++i5) {
                        e = t[i5];
                        int prod2 = abc*e;
                        if(!valid(prod2, 1000))
                            continue;
                        int prod = abc* (d*10+e);
                        if(valid(prod, 10000)) {
                            ++count;
                        }
                    }
                }
            }
        }

    }
    fout << count << endl;
    return 0;
}