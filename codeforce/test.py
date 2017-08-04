#!/usr/bin/python3
# -*- coding: UTF-8 -*-
def solve(a, b):
    l = 0
    r = 10000007
    s = a*b
    while (l <= r):
        mid = (l+r)/2
        if mid*mid*mid == s and mid%a == 0 and mid%b == 0:
        	return 1
        if mid*mid*mid < s:
        	l = mid+1
        else:
        	r = mid-1
    return 0;
t = int(input())
for i in range(n):
    a = input()
    b = input()
    r = solve(a, b);
    if r == 1:
    	print "YES"
    else:
    	print "NO"