import re
s = raw_input()
p = re.compile(r'a*b+a*')
lis = p.findall(s)
maxa = 0
print lis
for i in lis:
    maxa = max(maxa, len(i))
print maxa