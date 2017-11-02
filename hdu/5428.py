T = int(raw_input())
p = list()
def fenJie(x):
    i = 2
    p.append(x)
    while True:
        if i > x: break;
        if x % i == 0:
            p.append(i)
            while x % i == 0: x /= i
        i += 1

for _ in range(T):
    n = int(raw_input())
    a = map(int, raw_input().split())
    for i in a:
        fenJie(i)
    p = list(set(p))
    print p[0]*p[1]