#include <cstdio>
#include <cstring>
#include <cstdlib> 
 
const int MAXN = 200 + 10;
 
int n, mp[MAXN][MAXN], a[MAXN];
 
int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
 
int main(){
    freopen("in.txt", "r", stdin);  
 
    int ans;
    while(scanf("%d", &n) != EOF){
        memset(a, 0, sizeof(a)); 
 
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%d", &mp[i][j]);
                a[j] += mp[i][j]; 
            }
        }
 
        ans = 0; 
        qsort(a, n, sizeof(a[0]), cmp);
 
        int i = 0;
        while(i + 1 < n && a[i] < 0){
            if( a[i+1] + a[i] < 0 ){
                ans -= (a[i] + a[i+1]);
            }else{
                ans += (a[i] + a[i+1]);
            }
            i = i + 2;
        }
        for( ; i<n; ++i){
            ans += a[i];
        }
 
        printf("%d\n",  ans );
    }
    return 0;
}