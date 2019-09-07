/*
ID: codefor3
TASK: agrinet
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
#include <numeric>

// kruskal algorithm
using namespace std;
int g[101][101] = {};
const int INF = 1e9;
struct edge {
    int cost, u, v;
};

class disjoint_set {
public:
    vector<int> id;
    int size = 0;
    void init(int n) {
        id.resize(n);
        size = n;
        iota(id.begin(), id.end(), 0);
    }
    
    bool join(int p, int q) {
        int pid = find(p);
        int qid = find(q);
        if(pid == qid) return false;
        id[pid] = qid;
        --size;
        return true;
    }

    int find(int p) {
        int r = p;
        while(r != id[r]) {
            r = id[r];
        }
        int x = p;
        while(x != r) {
            int tmp = id[x];
            id[x] = r;
            x = tmp;
        }
        return r;
    }

};
int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> g[i][j];
    vector<edge> edges;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            edges.push_back({g[i][j], i, j});
        }
    }
    auto cmp = [] (const edge& e1, const edge& e2) {
        return e1.cost < e2.cost;
    };
    sort(begin(edges), end(edges), cmp);
    disjoint_set ds;
    ds.init(n);

    int total = 0;
    for(auto& e : edges) {
        if(ds.find(e.v) != ds.find(e.u)) {
            ds.join(e.v, e.u);
            total += e.cost;
        }
        if(ds.size == 1)
            break;
    }
    fout << total << endl;
    return 0;
}

