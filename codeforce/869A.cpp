#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[2005], b[2005];
    set<int> s;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++){cin >> a[i]; s.insert(a[i]);}
    for (int i = 1; i <= n; i++){cin >> b[i]; s.insert(b[i]);}
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
                if (s.find(a[i]^b[j]) != s.end()) cnt++;
        }
    puts(cnt&1 ? "Koyomi" : "Karen");
    return 0;
}