#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
struct node {
    string ra;
    string rb;
}a[105];
bool cmp(node a, node b) {
    return a.rb < b.rb;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ra;
        a[i].rb = a[i].ra;
        a[i].rb.erase(remove(a[i].rb.begin(), a[i].rb.end(), '.'), a[i].rb.end());
    }
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].ra << endl;
    return 0;
}