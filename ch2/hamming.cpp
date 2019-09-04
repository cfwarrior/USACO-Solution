/*
ID: codefor3
TASK: hamming
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
int N, B, D, M;
int hamming(int p, int q) {
    int ham = 0;
    for(int i= 0; i < B; ++i) {
        ham += ((p&1) ^ (q&1));
        p /= 2; q/=2;
    }
    return ham;
}

bool dfs(vector<int>& path, int start) {
    for(int i = start; i <= M; ++i) {

    }
}
void valid (int num, vector<int>& path) {
    for(auto i : path) {
        if(hamming(i, num) < D)
            return;
    }
    path.push_back(num);
}
int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");

    fin >> N >> B >> D;
    M = (1 << B) - 1;
    vector<int> path = {0};
    for(int i = 1; i <= M; ++i) {
        valid(i, path);
        if(path.size() == N)
            break;
    }
    for(int i = 0; i < N; ++i) {
        if(i != 0 && i%10)
            fout << " ";
        fout << path[i];
        if(i%10 == 9 || i == N-1)
            fout << endl;
    }
    return 0;
}