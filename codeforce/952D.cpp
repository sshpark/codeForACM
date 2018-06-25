#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
typedef pair<ll, ll> pii;
ll x;
struct cmp {
    bool operator () (const pii &u, const pii &v) {
        if (u.first == v.first) return u.second > v.second;
        return u.first > v.first;
    }
};

priority_queue<pii, vector<pii >, cmp> q, p;

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        q.push(make_pair(x, i));
    }
    
    while (q.size() > 1) {
        pii top = q.top(); q.pop();
        pii temp = q.top();
        if (temp.first == top.first) {
            q.pop();
            q.push(make_pair(temp.first*2, temp.second));
        } else p.push(make_pair(top.second, top.first));
    }
    p.push(make_pair(q.top().second, q.top().first));
    cout << p.size() << endl;
    while (!p.empty()) {
        cout << p.top().second << " ";
        p.pop();
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// struct cmp {
//     bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) {
//         if (a.first == b.first) return a.second > b.second;
//         return a.first > b.first;
//     }
// };

// priority_queue < pair<ll, ll>, vector<pair<ll, ll> >, cmp > a, b;

// ll n, x, y;
// ll li, ri;


// int main() {
//     cin.sync_with_stdio(false); cin.tie(NULL);
//     cin >> n;
//     for (ll i = 0; i < n; ++i) {
//         cin >> x;
//         a.push(make_pair(x, i));
//     }
//     while (a.size() > 1) {
//         x = a.top().first;
//         li = a.top().second;
//         a.pop();
//         y = a.top().first;
//         ri = a.top().second;
//         if (x == y) {
//             a.pop();
//             a.push(make_pair(y * 2, ri));
//         } else
//             b.push(make_pair(li, x));
//     }
//     b.push(make_pair(a.top().second, a.top().first));
//     cout << b.size() << endl;
//     while (!b.empty()) {
//         cout << b.top().second << " ";
//         b.pop();
//     }
//     return 0;
// }