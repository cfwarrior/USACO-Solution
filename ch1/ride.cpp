/*
ID: codefor3
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int mod = 47;

int get(string s) {
    long product = 1;
    for(auto& c : s) {
        product = (product * (c-'A'+1)) %mod;
    }
    return product;
}
int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    string group, comet;
    fin >> comet >> group;
    if(get(comet) == get(group)) {
        fout << "GO" << endl;
    }
    else {
        fout << "STAY" << endl;
    }
    return 0;
}

