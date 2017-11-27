n = int(raw_input())
for t in range(n):
    str1 = raw_input()
    str2 = raw_input()
    dct = dict()
    flag = True
    for c in str1:
        dct[c] = 1
    for c in str2:
        if dct.get(c, 0) == 0:
            print -1
            flag = False
            break;
    if flag:
        rep = len(str2)/len(str1)
        temp_str = str1*rep
        for i in range(0, 3, 1):
            if str2 in temp_str:
                print rep+i
                flag = False
                break;
            temp_str = temp_str + str1
        if flag:
            print -1