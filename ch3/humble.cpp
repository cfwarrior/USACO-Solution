/*
ID: codefor3
TASK: humble
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

int pIndex[101] = {};
long long humble[100001] = {};
long long INF = 1e12;

int main() {
    ofstream fout ("humble.out");
    ifstream fin ("humble.in");
    int K, N;
    fin >> K >> N;
    vector<int> prime(K);
    for(int k = 0; k < K; ++k) {
        fin >> prime[k];
    }
    humble[0] = 1;
    for(int i = 1; i <= N;) {
        long long next = INF;
        int index = -1;
        // find next humble number
        for(int k = 0; k < K; ++k) {
            if(prime[k] * humble[pIndex[k]] < next) {
                index = k;
                next = prime[k] * humble[pIndex[k]];
            }
        }
        // handle duplicates
        if(next != humble[i-1]) {
            humble[i++] = next;
        }
        pIndex[index]++;
    }
    fout << humble[N] << endl;
    return 0;
}