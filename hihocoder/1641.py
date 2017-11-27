n, m = list(map(int, raw_input().split()))
a = [2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9]
dic = dict()
for i in range(n):
    s = raw_input()
    x = 0
    for j in range(len(s)): x = x*10+a[ord(s[j])-ord('A')]
    dic[x] = dic.get(x, 0) + 1


for i in range(m):
    l = int(raw_input())
    print dic.get(l, 0)