/*
ID: codefor3
TASK: nocows
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    int n, k;
    fin >> n >> k;

    if(n%2 == 0) {
        fout << 0 << endl;
        return 0;
    }    
    


    return 0;
}