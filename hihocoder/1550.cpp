#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int v[100000 + 10];
int main () {
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; ++i) cin >> v[i];
  ll t1 = 0;
  ll t12 = 0;
  ll t123 = 0;
  for(int i = 0; i < N; ++i) {
    const int c = v[i];
    if (c == 1) {
      t1++;
    } else if (c == 2) {
      t12 += t1;
    } else if (c == 3) {
      t123 += t12;
    }
  }


  cout << t123 << endl;
}