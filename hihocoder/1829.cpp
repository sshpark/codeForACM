#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long

map<string, int> mm, vis;
void getsub(string str) {
    int len = str.length();
    int n = 1<<len;
    str += str;
    vis.clear();
    string temp, ans;
    for (int st = 0; st < len; st++) {
        temp = str.substr(st, len);
        for (int i = 1; i < n; i++) {
            ans = "";
            for (int j = 0; j < len; j++) {
                if (i&(1<<j)) {
                    ans += temp[j];
                }
            }
            if (!vis[ans]) {
                vis[ans] = 1;
                mm[ans]++;    
            }
            
        }
    }
}
inline bool cmp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() > b.length();
}

int main(int argc, char const *argv[])
{
    int n;
    string str;
    while (cin >> n) {
        mm.clear();
        for (int i = 0; i < n; i++) {
            cin >> str;
            getsub(str);
        }
        int maxa = 0;
        string ans = "";
        vector<string> v;
        for (auto it : mm) {
            if (it.second == n) {
                if (it.first.length() > maxa) {
                    maxa = max((int)it.first.length(), maxa);
                    ans = it.first;
                }
                // v.push_back(it.first);
            }
        }
        if (ans != "")
            cout << ans << endl;
        else 
            cout << "0" << endl;
    }

    return 0;
}