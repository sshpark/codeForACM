#coding=utf8
while True:
    try:
        s = int(input())
        a, b = 1, 2
        he = 0
        if s == a:
            print(1)
        elif s == b:
            print(2)
        else:
            for i in range(3, 20000):
                he = a+b
                if he == s:
                    print(i)
                    break;
                a = b
                b = he
    except EOFError:  
        break
exit(0)