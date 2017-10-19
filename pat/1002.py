str = input()
du = ('ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu', 'shi')
ans = 0
for i in str: ans += int(i)
r = list()
while ans != 0:
    r.append(ans%10)
    ans //= 10
for i in range(len(r)-1, 0, -1):
    print(du[r[i]], end=' ')
print(du[r[0]])