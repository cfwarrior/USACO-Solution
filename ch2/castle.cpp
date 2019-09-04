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
#include <unordered_map>

using namespace std;

typedef vector<vector<int>> vvi;

// W N E S
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int i, int j, const vvi& wall, vvi& castle, int color) {
    // colored
    if(castle[i][j])
        return;
    castle[i][j] = color;
    for(int k = 0; k < 4; ++k) {
        if(!(wall[i][j] & (1 << k))) {
            dfs(i+dx[k], j+dy[k], wall, castle, color);
        }
    }
}

void print(vvi& matrix) {
    for(auto & row : matrix) {
        for(auto c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int n, m;
    fin >> n >> m;
    vvi wall(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            fin >> wall[i][j];
        }
    }
    vvi castle(m, vector<int>(n, 0));
    int color = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!castle[i][j]) {
                dfs(i, j , wall, castle, ++color);
            }
        }
    }
    fout << color << endl;
    int largest = 0;
    // area of each room
    unordered_map<int, int> count;
    for(auto& r : castle) {
        for(auto c : r) {
            count[c]++;
            largest = max(largest, count[c]);
        }
    }
    fout << largest << endl;
    char edge;
    int mx = 0, r, c;
    for(int j = 0; j < n; ++j) {
        for(int i = m-1; i >= 0; --i) {
            if(i != 0 && castle[i][j] != castle[i-1][j]) {
                // remove 'N'
                int area = count[castle[i][j]] + count[castle[i-1][j]];
                if(area > mx) {
                    r = i+1; c = j+1; edge = 'N';
                    mx = area;
                }
            }
            if(j < n-1 && castle[i][j] != castle[i][j+1]) {
                // remove 'E'
                int area = count[castle[i][j]] + count[castle[i][j+1]];
                if(area > mx) {
                    r = i+1; c = j+1; edge = 'E';
                    mx = area;
                }
            }
        }
    }
    fout << mx << endl;
    fout << r << " " << c << " " << edge << endl; 
    return 0;
}