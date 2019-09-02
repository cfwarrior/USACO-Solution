/*
ID: codefor3
TASK: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> keypad = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

void dfs(vector<string>& names, unordered_set<string>& dict, string& num, const string& path, int i) {
    if(i == num.size() && dict.find(path) != dict.end()) {
        names.push_back(path);
        return;
    }

    for(auto& c : keypad[num[i]-'0']) {
        dfs(names, dict, num, path+c, i+1);
    }

}

int main() {
    ofstream fout ("namenum.out");
    ifstream dic ("dict.txt");
    ifstream fin ("namenum.in");
    unordered_set<string> dict;
    string w, num;
    while(dic >> w)
        dict.insert(w);
    fin >> num;
    vector<string> names;
    dfs(names, dict, num, "", 0);
    if(names.size() == 0) {
        fout << "NONE" << endl;
    }
    else {
        sort(names.begin(), names.end());
        for(auto& name : names) {
            fout << name << endl;
        }
    }
    
    return 0;
}