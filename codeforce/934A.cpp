#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
vector<pair<long long int, int> > v;
long long int a[55], b[55];
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    long long int mina = LLONG_MIN;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int pos = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (mina < a[i]*b[j]) {
                mina = a[i]*b[j];
                pos = i;
            }
            v.push_back(make_pair(a[i]*b[j], i));
        }
    sort(v.begin(), v.end());
    for (int i = (int)v.size()-1; i >= 0; --i)
        if (v[i].second != pos) {
            cout << v[i].first << endl;
            break;
        }
    return 0;
}