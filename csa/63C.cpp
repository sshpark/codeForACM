#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int maxn = 100005;
map<int, int> mm;
map<int, int>::iterator it;
int a[maxn];
void approximateNumber(int n){  
    int i;
    for(i=2;i*i<n;i++){  
        if(n%i == 0){  
            mm[i]++;  
            mm[n/i]++;
        }  
    }
    if(i*i == n) mm[i]++;
}
int main(int argc, char const *argv[])
{
    int n, x, flag = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] -= x;
        if (a[i] < 0) flag = 1;
    }
    if (flag) printf("-1\n");
    else {
        for (int i = 0; i < n; i++)
            approximateNumber(a[i]);
        it = mm.begin();
        while (it != mm.end()) {
            if (it->second == n) return 0*printf("%d\n", it->first);
            it++;
        }
        printf("-1\n");
    }

    return 0;
}