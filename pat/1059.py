import sys
n = int(input())
rank = {}
for i in range(n): rank[input()] = i
m = int(input())
for i in range(m):
    check = input()
    if rank.get(check) == None: print(‘%04d: Are you kidding?’ % check)
    else:
        if rank[check] == 0: print(‘%04d: Mystery Award’ % check)
        elif rank[check]%2 == 0: print(‘%04d: Minion’ % check)
        elif rank[check]%2 != 0: print(‘%04d: Chocolate’ % check)
sys.exit(0)