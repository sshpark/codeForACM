T = int(raw_input())
def ok(a, b, c):
    if a == 'C' and b == 'C' and c == 'C': return True;
    if a == 'C' and b == 'P' and c == 'C': return True;
    if a == 'C' and b == 'C' and c == 'P': return True;
    return False;
for _ in range(T):
    n = int(raw_input())
    vis = [0]*n;
    str = raw_input()
    ans = 0
    for i in range(n-3):
        if str[i] == 'C' and str[i+1] == 'C' and str[i+2] == 'P' and str[i+3] == 'C':
            ans += 1
            vis[i+1] = vis[i+2] = 1;
    for i in range(n-2):
        if ok(str[i], str[i+1], str[i+2]) and vis[i] == 0 and vis[i+1] == 0 and vis[i+2] == 0:
            ans += 1;
            break;
    print ans