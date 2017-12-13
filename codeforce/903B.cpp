#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int h1, a1, c1, h2, a2;
    vector<string> str;
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    while (true) {
        if (h2-a1 <= 0) {
            str.push_back("STRIKE");
            break;
        }
        if (h1 <= a2) {
            h1 += c1;
            h1 -= a2;
            str.push_back("HEAL");
        } else {
            str.push_back("STRIKE");
            h1 -= a2;
            h2 -= a1;
        }
        if (h2 <= 0) break;
    }
    printf("%d\n", (int)str.size());
    for (auto i : str)
        cout << i << endl;
    return 0;
}