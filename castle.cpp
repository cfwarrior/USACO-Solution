/*
ID: codefor3
TASK: castle
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
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}