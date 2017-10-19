n = int(raw_input())
a = map(int, raw_input().split())
m = {0: 0}
for i in xrange(0, n): m[a[i]] = i+1
for i in xrange(n-1, 0, -1):
    if m[i] > m[i+1]:
        print i
        break