# -*- coding: utf-8 -*-
from __future__ import print_function
n = int(raw_input())
nsum = 0
for i in range(1, 27):
    pos = 100
    for j in range(1, 101):
        if nsum+j*(j-1)//2 > n:
            pos = j-1
            break
    for j in range(1, pos+1):
        print(chr(96+i), end='')
    nsum += (pos*(pos-1))//2
    if nsum == n:
        break
print()