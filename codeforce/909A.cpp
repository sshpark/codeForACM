#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    string a, b, c, re;
    re = "zzzzzzzzzzzzzz";
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            c = a.substr(0, i) + b.substr(0, j);
            if (c.compare(re) < 0) re = c;
        }
    }
    cout << re << endl;
    return 0;
}