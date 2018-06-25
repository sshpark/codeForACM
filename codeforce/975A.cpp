#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
set<string> s;
vector<string> v;
int main(int argc, char const *argv[])
{
    int n, len;
    string temp, temp1, temp2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        temp1 = "";
        len = (int)temp.size();
        sort(temp.begin(), temp.end());
        temp1 += temp[0];
        for (int i = 1; i < len; i++)
            if (temp[i] != temp[i-1]) temp1 += temp[i];
        s.insert(temp1);
    }
    // len = v.size();
    // int len1;
    // for (int i = 0; i < len; i++) {
    //     temp = v[i];
    //     s.insert(temp);
    //     for (int j = i+1; j < len; j++) {
    //         temp += v[j];
    //         // cout << temp << endl;
    //         temp2 = temp;
    //         temp1 = "";
    //         len1 = (int)temp2.size();
    //         sort(temp2.begin(), temp2.end());
    //         temp1 += temp2[0];
    //         for (int k = 1; k < len1; k++)
    //             if (temp2[k] != temp2[k-1]) temp1 += temp2[k];
    //         s.insert(temp1);            
    //     }
    // }
    // for (auto i : s) cout << i << endl;
    cout << s.size() << endl;
    return 0;
}