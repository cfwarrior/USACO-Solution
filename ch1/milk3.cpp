/*
ID: codefor3
TASK: milk3
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

// TODO: write DFS solution
// reduce visited dimension to 2
// pour(from, to, cap);

using namespace std;

bool visited[21][21][21];

struct State {
    int a, b , c;
};

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    int A, B, C;
    fin >> A >> B >> C;
    // bfs all possible case;
    queue<State> q;
    q.push({0, 0, C});
    visited[0][0][C] = true;
    int a, b, c, delta;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        // push all variation after pouring to q;
        // pour from c
        if(cur.c > 0) {
            // to a
            delta = min(cur.c, A-cur.a);
            a = cur.a+delta; b = cur.b; c = cur.c-delta;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }
            // to b
            delta = min(cur.c, B-cur.b);
            a = cur.a; b = cur.b + delta; c = cur.c - delta;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }           
        }

        // pour from a
        if(cur.a > 0) {
            // to b
            delta = min(cur.a, B-cur.b);
            a = cur.a-delta; b = cur.b + delta; c = cur.c;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }
            // to c
            delta = min(cur.a, C-cur.c);
            a = cur.a-delta; b = cur.b ; c = cur.c + delta;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }           
        }
        // pour from b
       if(cur.b > 0) {
            // to a
            delta = min(cur.b, A-cur.a);
            a = cur.a+delta; b = cur.b - delta; c = cur.c;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }
            // to c
            delta = min(cur.b, C-cur.c);
            a = cur.a; b = cur.b - delta; c = cur.c+delta;
            if(!visited[a][b][c]) {
                q.push({a, b, c});
                visited[a][b][c] = true;
            }           
        }       
    }
    vector<int> res;
    // output all valid state
    for(int c = 0; c <= 20; c++) {
        for(int b = 0; b <= 20; b++) {
            if(visited[0][b][c]) {
                res.push_back(c);
            }
        }
    }
    fout << res[0];
    for(int i = 1; i < res.size(); ++i)
        fout << " " << res[i];
    fout << endl;
    return 0;
}