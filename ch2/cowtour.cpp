/*
ID: codefor3
TASK: cowtour
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>   
#include <iomanip>    

using namespace std;
const int MAXN = 151;
const double inf = 1e12;
bool connected[MAXN][MAXN] = {};
double dist[MAXN][MAXN] = {};
int X[MAXN] = {};
int Y[MAXN] = {};
int N;

double calc(int a, int b, int c, int d) {
    return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}

int main() {
    freopen("cowtour.in", "r", stdin); 
    freopen("cowtour.out", "w", stdout); 
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    string line;
    for(int i = 0; i < N; ++i) {
        cin >> line;
        for(int j = 0; j < N; ++j) {
            connected[i][j] = line[j] == '1';
            if(connected[i][j]) {
                dist[i][j] = calc(X[i], Y[i], X[j], Y[j]);
            }
            else {
                dist[i][j] = inf;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        dist[i][i] = 0.0;

    // floyd
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // for(int i = 0; i < N; ++i) {
    //     for(int j = 0; j < N; ++j) {
    //         fout << dist[i][j] << " ";
    //     }
    //     fout << endl;
    // }
    double diameter[N] = {0.0};
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(dist[i][j] != inf) {
                diameter[i] = max(diameter[i], dist[i][j]);
            }
        }
    }


    double ans = inf;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(dist[i][j] != inf) continue;
            double path = calc(X[i], Y[i], X[j], Y[j]);
            ans = min(ans, diameter[i] + diameter[j] + path);
        }
    }
    // diameter may still be limited within  a single component
    for(int i = 0; i < N; ++i) {
        ans = max(ans, diameter[i]);
    }
    printf("%.6f\n", ans);
    return 0;
}