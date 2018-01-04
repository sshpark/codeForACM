#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[100005];
int main(int argc, char const *argv[])
{
    int n;
    int dis = 1000000000;
    int mina = 1000000001;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == mina) {
            pos = i;
            break;
        }
    for (int i = pos+1; i < n; i++) {
        if (a[i] == mina) {
            dis = min(dis, i-pos);
            pos = i;
        }
    }
    printf("%d\n", dis);
    return 0;
}