/*
ID: codefor3
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int year) {
    if(year%100 == 0)
        return year%400 == 0;
    return year%4 == 0;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n = 0;
    fin >> n;
    vector<int> freq(7);
    int d = 6;      // first 13th is Saturday
    for(int i = 1900; i < 1900+n; ++i) {
        for(int j = 0; j < 12; ++j) {
            freq[d]++;
            if(leap(i) && j == 1) {
                ++d;
            }
            d = (d + days[j])%7;
        }
    }
    rotate(freq.begin(), freq.begin()+6, freq.end());
    for(int i = 0; i < 7; ++i) {
        if(i == 0)
            fout << freq[i];
        else
        {
            fout << " " << freq[i];
        }
    }
    fout << endl;
}