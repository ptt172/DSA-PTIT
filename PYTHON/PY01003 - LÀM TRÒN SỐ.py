for _ in range (int(input ())) :
    n = int (input())
    p = 10
    while n > p:
        if n %p >= p // 2:
            n = n - n %p + p
        else : n = n - n % p
        p *= 10
    print (n)