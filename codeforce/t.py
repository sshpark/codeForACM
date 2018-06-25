T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    n = n+1
    s = n*(n+1)*(n+2)/6
    print(int(s%m))