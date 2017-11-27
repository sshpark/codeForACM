k = int(input())
s = input()
st = set(s)
if len(st) < k:
    print("NO")
else:
    st = set()
    print("YES")
    cnt = 0
    pos = 0
    st.add(s[0])
    for i in range(len(s)):
        if cnt == k-1:
            pos = i
            break
        if s[i] not in st:
            print(s[i], end='')
        else:
            cnt += 1
            st.add(s[i+1])
            print(s[i+1])
    print(s[pos:])