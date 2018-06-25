#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
vector<pair<long long int, int> > v;
int main(int argc, char const *argv[])
{
    int T, P, A, B;
    cin >> T;
    while (T--) {
        bool first = true;
        cin >> P >> A >> B;
        for (int i = 1; i < P; i++) {
            ll sum = 1;
            for (int j = 1; j <= A; j++)
                sum = ((sum%P)*(i%P))%P;
            if (sum == B) {
                if (first) {
                    printf("%d", i);
                    first = false;
                } else printf(" %d", i);
            }
        }
        if (first) printf("No Solution\n");
        printf("\n");
    }
    return 0;
}