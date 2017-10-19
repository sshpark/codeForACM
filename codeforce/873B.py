#!/usr/bin/python
n = int(raw_input())
s = raw_input()
m = {0: 0}
cnt = 0
ans = 0
for i in xrange(n):
    if s[i] == '0': cnt -= 1
    else: cnt += 1
    if cnt not in m:
        m[cnt] = i+1
    else:
        ans = max(ans, i - m[cnt] + 1)
print ans