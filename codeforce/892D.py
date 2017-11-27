import copy
n = int(input())
a = list(map(int, input().split()))
b = list()
dic = dict()
for i in range(n): dic[a[i]] = i
dic = [(k, dic[k]) for k in sorted(dic.keys())]
for i in range(n):
    b[dic.get(a[i], 0)]