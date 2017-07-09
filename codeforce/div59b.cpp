#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
//#define LOCAL

int a[1005];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
    int n(0), k(0); scanf("%d %d", &n, &k);
    int *rank = new int[n];
    for(int p = 0; p < n; p++){scanf("%d", rank + p);}

    long coins(0);
    while(rank[0] < k){
        for(int p = 0; p < n; p++){
            if(rank[p] == k){break;}
            else if((p == n - 1) || (rank[p] < rank[p + 1])){++rank[p];}
        }
        ++coins;
    }

    printf("%ld\n", coins);

    delete[] rank;
    return 0;
}