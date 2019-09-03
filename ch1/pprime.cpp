/*
ID: codefor3
TASK: pprime
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

string getEven(const string& base) {
    string res = base;
    for(int i = base.size()-1; i >= 0; --i)
        res += base[i];
    return res ;
}
string getOdd(const string& base) {
    string res = base;
    for(int i = base.size()-2; i >= 0; --i)
        res += base[i];
    return res;
}

bool isprime(long n) {
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}
int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    int a, b;
    fin >> a >> b;

    // build palidrome
    vector<int> res;
    int base = 1;
    string even, odd;
    for(; base <= b; ++base) {
        string root = to_string(base);
        even = getEven(root);
        odd = getOdd(root);
        long e = stol(even), o = stol(odd);
        if(e > b && o > b)
            break;
        if(e >= a && e <= b && isprime(e)) {
            res.push_back(e);
        }
        if(o >= a && o <= b && isprime(o)) {
            res.push_back(o);
        }
    }
    sort(res.begin(), res.end());
    for(auto& p : res)
        fout << p << endl;
    return 0;
}