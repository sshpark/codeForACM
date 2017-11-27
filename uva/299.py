T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = 0
    for i in range(n):
        for j in range(i+1, n):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
                cnt += 1
    print("Optimal train swapping takes", cnt, "swaps.")