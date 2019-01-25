import math
n = int(input())
i = 0
t = 1
s = 0
while s < n:
    i = i+1
    s += t
    t *= 3
print(i)