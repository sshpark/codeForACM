#include <iostream>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;

    int O, R;
    int MINRO = INF, SUMO = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &R, &O);
        SUMO += O;
        if (R - O < MINRO)
        {
            MINRO = R - O;
        }
    }

    std::cout << SUMO + MINRO << '\n';
    return 0;
}