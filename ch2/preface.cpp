/*
ID: codefor3
TASK: preface
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
vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
string toRoman(int n) {
    string res;
    for(int i = 0; i < nums.size(); ++i) {
        if(n >= nums[i]) {
            int c = n / nums[i];
            for(int k = 0; k < c; ++k) {
                res += strs[i];
            }
            n -= c*nums[i];
        }
    }
    return res;
}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n;
    fin >> n;

    unordered_map<char, int> count;
    for(int i = 1; i <= n; ++i) {
        string str = toRoman(i);
        for(auto& c : str) {
            count[c]++;
        }
    }
    string ROMAN = "IVXLCDM";
    for(auto c : ROMAN) {
        if(count[c]) {
            fout << c << " " << count[c] << endl;
        }
    }

    return 0;
}