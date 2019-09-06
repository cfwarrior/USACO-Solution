/*
ID: codefor3
TASK: ttwo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int N = 10;
ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");

bool visited[101][101][4][4] = {};
vector<string> board(N);
int dx[4] = {-1,  0,  1,  0};
int dy[4] = { 0,  1,  0, -1};
int df = 0, dc = 0;     // facing north
// F :(i, j), C:(x,y)
int xf, yf, xc, yc;
void turn(int& d) {
    d = (d + 1)%4;
}

void read() {
    for(int i = 0; i < N; ++i) {
        fin >> board[i];
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == 'F') {
                xf = i; yf = j;
            }
            if(board[i][j] == 'C') {
                xc = i; yc = j;
            }
        }
    } 
    // fout << xf << " " << yf << endl;
    // fout << xc << " " << yc << endl;
    visited[xf*N+yf][xc*N+yc][df][dc] = true;  
}

bool check(int x, int y) {
    if(x < 0 || y < 0 || x >= N || y >= N || board[x][y] == '*')
        return false;
    return true;
}

int main() {
    int time = 0;
    read();
    while(true) {
        
        if(check(xf+dx[df], yf+dy[df])) {
            xf += dx[df]; yf += dy[df];
        }
        else {
            turn(df);
        }
        if(check(xc+dx[dc], yc+dy[dc])) {
            xc += dx[dc]; yc += dy[dc];
        }
        else {
            turn(dc);
        }
        time++;
        if(xf == xc && yf == yc) {
            fout << time << endl;
            return 0;
        }
        
        if(visited[xf*N+yf][xc*N+yc][df][dc]) {
            fout << 0 << endl;
            return 0;
        }
        visited[xf*N+yf][xc*N+yc][df][dc] = true;
    }
    return 0;
}