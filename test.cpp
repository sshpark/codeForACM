#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int n, m, q;
const int mycount = 100005;
int a[mycount];
int h[mycount];
int l[mycount];
vector<int> game[mycount];
int qu[mycount], qv[mycount];
int parent[mycount];

int getparent(int i) {
    if (i == parent[i])
        return i;
    parent[i] = getparent(parent[i]);
    return parent[i];
}

vector<int> queryArray[mycount];
void reinitQuery() {
    int i, j;
    
    for (i = 1; i <= n; i++)
        parent[i] = i;
    
    for (i = 1; i <= q; i++) {
        queryArray[i].clear();
    }
    
    for (i = 1; i <= m; i++) {
        if (l[i] <= h[i]) {
            int mid = (l[i] + h[i]) >> 1;
            queryArray[mid].push_back(i);
        }
    }
}

void merge(int i, int j) {
    parent[getparent(i)] = getparent(j);
}

bool verify(int gameno) {
    int i, j, p;
    
    j = game[gameno][0];
    p = getparent(j);
    for (i = 1; i < game[gameno].size() && p == getparent(game[gameno][i]); i++);
    if (i == game[gameno].size())
        return true;
    return false;
}

void process() {
    int i, j, k, v, c;
    
    
    for (int t = 0; t < 20; t++) {
        reinitQuery();
        // cout<<"t = "<<t<<endl;
        for (i = 0; i <= q; i++) {
            for (j = 0; j < queryArray[i].size(); j++) {
                k = queryArray[i][j];
                
                if (verify(k)) {
                    h[k] = i;
                } else {
                    l[k] = i + 1;
                }
            }
            
            if (i < q)
                merge(qu[i], qv[i]);
            
        }
    }
    for (i = 1; i <= m; i++) {
        if (l[i] == q + 1) {
            printf("-1\n");
            
        } else {
            printf("%d\n", l[i]);
        }
    }
}

int main() {
    int i, j, k;
    while (~scanf("%d %d %d", &n, &m, &q)) {
        for (int i = 0; i < n; i++) {
            game[i].clear();
        }
        for (i = 1; i <= n; i++) {
            scanf("%d", &j);
            game[j].push_back(i);   
        }
        
        for (i = 0; i < q; i++) {
            scanf("%d %d", &qu[i], &qv[i]);
        }
        
        for (i = 1; i <= m; i++) {
            h[i] = q;
            l[i] = 0;
        }
        process();
    }
    
    return 0;
}