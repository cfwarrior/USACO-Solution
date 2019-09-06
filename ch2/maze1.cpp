/*
ID: codefor3
TASK: maze1
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
int W, H;
vector<string> maze(210);
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    fin >> W >> H;
    W = 2*W+1;
    H = 2*H+1;
    string tmp;
    getline(fin, tmp);
    for(int i = 0; i < H; ++i) {
        getline (fin,maze[i]);
    }
    queue<pair<int,int>> q;
    // find two exit
    for(int j = 0; j < W; ++j) {
        if(maze[0][j] == ' ') {
            q.push({0,j});
            maze[0][j] = '.';
        }
        if(maze[H-1][j] == ' ') {
            q.push({H-1, j});
            maze[H-1][j] = '.';
        }
    }
    for(int i = 1; i < H-1; ++i) {
        if(maze[i][0] == ' ') {
            q.push({i,0});
            maze[i][0] = '.';
        }
        if(maze[i][W-1] == ' ') {
            q.push({i, W-1});
            maze[i][W-1] = '.';
        }
    }
    int steps = 0;
    int x, y, i, j;
    while(!q.empty()) {
        int len = q.size();
        for(int k = 0; k < len; ++k) {
            x = q.front().first; y = q.front().second; 
            q.pop();
            for(int kk = 0; kk < 4; ++kk) {
                i = x + dx[kk]; j = y + dy[kk];
                if(i >= 0 && j >= 0 && i < H && j < W && maze[i][j] == ' ') {
                    // fout << i << " " << j << endl;
                    q.push({i, j});
                    maze[i][j] = '.';
                }
            }
        }
        ++steps;
    }
    fout << steps/2 << endl;
    return 0;
}