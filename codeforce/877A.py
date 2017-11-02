s = raw_input()
cnt = 0
cnt += s.count('Danil');
cnt += s.count(r'Olya')
cnt += s.count(r'Slava')
cnt += s.count(r'Ann')
cnt += s.count(r'Nikita')
if cnt == 1: print 'YES'
else: print 'NO'