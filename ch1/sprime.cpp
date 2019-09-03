/*
ID: codefor3
TASK: sprime
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

bool isPrime(int n) {
    if(n%2 == 0)
        return n == 2;
    if(n%2 == 0) return false;
    for(int i = 3; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    int n;
    fin >> n;
    vector<int> ribs = {2,3,5,7};
    for(int i = 1; i < n; ++i) {
        // genrate longer ribs
        vector<int> next;
        for(int k = 0; k < ribs.size(); ++k) {
            for(int j = 1; j <= 9; j+=2) {
                int tmp = ribs[k]*10 + j;
                if(isPrime(tmp)) {
                    next.push_back(tmp);
                }
            }
        }
        swap(next, ribs);
    }
    for(auto i : ribs) {
        fout << i << endl;
    }
    return 0;
}