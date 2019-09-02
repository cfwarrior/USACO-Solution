/*
ID: codefor3
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void rotate90(vector<vector<char>>& matrix) {
    int n = matrix.size();
    vector<vector<char>> transformed(n, vector<char>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            transformed[j][n-1-i] = matrix[i][j];
        }
    }
    matrix = transformed;
}
void reflect(vector<vector<char>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n/2; ++j) {
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }  
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<char>> target(n, vector<char>(n));
    string line;
    for(int i = 0; i < n; ++i) {
        fin >> line;
        matrix[i] = vector<char> (line.begin(), line.end());
    }
    for(int i = 0; i < n; ++i) {
        fin >> line;
        target[i] = vector<char> (line.begin(), line.end());
    }
    //
    vector<vector<char>> transform = matrix;
    for(int i = 1; i <= 3; ++i) {
        rotate90(transform);
        if(transform == target) {
            fout << i << endl;
            return 0;
        }
    }
    transform = matrix;
    reflect(transform);
    if(transform == target) {
        fout << 4 << endl;
        return 0;
    }
    for(int i = 1; i <= 3; ++i) {
        rotate90(transform);
        if(transform == target) {
            fout << 5 << endl;
            return 0;
        }
    }
    if(matrix == target) {
        fout << 6 << endl;
        return 0;       
    }
    fout << 7 << endl;
    return 0;
}


