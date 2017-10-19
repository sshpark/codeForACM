#include <queue>
#include <iostream>
using namespace std;
const int maxn = 400010;
int deq[maxn];
int main(int argc, char const *argv[])
{
    int T, n, x;
    char op[10];
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int dir = 1, head = 0, tail = 1, r = 200000, l = 200001;
        scanf("%d", &n);
        printf("Case #%d:\n", i);
        while (n--) {
            scanf("%s", op);
            if (op[2] == 'S') {
                scanf("%d", &x);
                if (dir) {
                    head++;
                    if (!x) deq[++r] = head;
                }
                else {
                    tail--;
                    if (!x) deq[--l] = tail;
                }
            }
            else if (op[2]=='P') {
                if (dir) {
                    head--;
                    if (l <= r && deq[r] > head) r--;
                }
                else {
                    tail++;
                    if (l <= r && deq[l] < tail) l++;
                }
            }
            else if (op[2] == 'V') dir = !dir;
            else {
                if (tail > head) puts("Invalid.");
                else if (l > r) printf("%d\n", (head-tail+1)&1);
                else {
                    if (dir) {
                        int g = deq[l] - tail;
                        if (head > deq[l]) g++;
                        printf("%d\n", g&1);
                    }
                    else {
                        int g = head - deq[r];
                        if (deq[r] > tail) g++;
                        printf("%d\n", g&1);
                    }
                }
            }
        }
    }
    return 0;
}