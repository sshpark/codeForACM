#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

int h, m;
int H, D, C, N;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> m;
    cin >> H >> D >> C >> N;
    double ans = 1e15;
    ans = min(ans, ceil(H * 1.0 / N) * C);
    if (h >= 20) {
        ans = min(ans, ceil(H * 1.0 / N) * C * 80.0 / 100.0);
    }
    else {
        int add = (20 - h) * 60 - m;
        H += add * D;
        ans = min(ans, ceil(H * 1.0 / N) * C * 80.0 / 100.0);
    }
    cout << setprecision(6) << fixed << ans << endl;
}