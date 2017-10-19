#!/usr/bin/python
a = map(int, raw_input().split())
now = 0
ans = 0
for i in range(1, a[0]+1):
    if a[i] - now > 0:
        ans += 6*(a[i]-now)+5
    else:
        ans += 4*(now - a[i])+5
    now = a[i]
print ans