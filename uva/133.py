while True:
    n, k, m = map(int, input().split())
    if n+k+m == 0: break
    que = [0]*n
    vis = [0]*n
    for _ in range(n):
        que[_] = _+1
        vis[_] = 1
    x, y = -1, n
    su = 0
    while su < n:
        if su > 0: print(',', end='')
        i = 0
        while i < k:
            x = (x+1)%n;
            if vis[x] == 1: i += 1
        i = 0
        while i < m:
            if y == 0: y = n-1
            else: y -= 1
            if vis[y] == 1: i += 1
        if x == y:
            vis[x] = 0
            su += 1
            print("%3d" % (que[x]), end='')
        else:
            vis[x] = vis[y] = 0
            su += 2
            print("%3d%3d" % (que[x], que[y]), end='')
    print()