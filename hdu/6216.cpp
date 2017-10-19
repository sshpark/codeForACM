#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<algorithm>  
#include<cstring>  
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
#define _size 500
#define file_in freopen("input.txt","r",stdin)
using namespace std;
const int maxn = 100010;
struct point {
    ll i;
    ll j;
};
ll vst[_size][_size];
vector<ll>ni, nj;
ll sum;
int di[] = { 0,0,-1,1 };
int dj[] = { 1,-1,0,0 };
void dfs(int i, int j)
{
    if (vst[i][j] || i >= ni.size() || i < 0 || j >= nj.size() || j < 0)return;
    sum +=(ll) ni[i] * (ll)nj[j];
    vst[i][j] = 1;
    for (int f = 0; f < 4; f++)
    {
        dfs(i + di[f], j + dj[f]);
    }
}
int main()
{
    int casei;
    scanf("%d", &casei);
    for (int i = 0; i < casei; i++)
    {
        ll ri, cj;
        scanf("%lld %lld", &cj, &ri);
        ll q;
        scanf("%lld", &q);
        vector<point>poi(q);
        for (int i = 0; i < q; i++)
        {
            scanf("%lld %lld", &poi[i].j, &poi[i].i);
        }
        printf("Case #%d:\n", i + 1);
        vector<ll>ii;
        vector<ll>jj;
        ii.push_back(0);
        ii.push_back(ri);
        jj.push_back(0);
        jj.push_back(cj);
        for (ll i = 0; i < q; i++)
        {
            ii.push_back(poi[i].i);
            jj.push_back(poi[i].j);
        }
        sort(ii.begin(), ii.end());
        sort(jj.begin(), jj.end());
        ll numi = unique(ii.begin(), ii.end()) - ii.begin();
        ll numj = unique(jj.begin(), jj.end()) - jj.begin();
        ni.clear();
        nj.clear();
        map<ll, ll>mi, mj;
        for (ll i = 1; i < numi; i++)
        {
            if (ii[i] - ii[i - 1] > 1)ni.push_back(ii[i] - ii[i - 1] - 1);
            ni.push_back(1);
            mi[ii[i]] = ni.size()-1 ;
        }
        for (ll j = 1; j < numj; j++)
        {
            if (jj[j] - jj[j - 1] > 1)nj.push_back(jj[j] - jj[j - 1] - 1);
            nj.push_back(1);
            mj[jj[j]] = nj.size()-1;
        }
        mem(vst, 0);
        for (int i = 0; i < q; i++)
        {
            vst[mi[poi[i].i]][mj[poi[i].j]] = 1;
        }
        vector<ll>ans;
        for (int i = 0; i < ni.size(); i++)
        {
            for (int j = 0; j < nj.size(); j++)
            {
                sum = 0;
                if (!vst[i][j])
                    dfs(i, j);
                if(sum)
                    ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            if (i)printf(" %lld", ans[i]);
            else printf("%lld", ans[i]);
        }
        printf("\n");
    }
}