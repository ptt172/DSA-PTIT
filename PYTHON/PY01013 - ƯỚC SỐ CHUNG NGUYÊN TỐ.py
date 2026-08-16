import math

def nt (n):
    if n < 2 : return False
    for i in range (2 , int(math.sqrt (n) + 1)):
        if n % i ==0:
            return False
    return n > 1
t = int (input ())
for _ in range (t):
    a , b = map (int , input().split ())
    ucln = math.gcd (a , b)
    tong = 0
    while ucln > 0 :
        tong += ucln % 10
        ucln //=10
    if (nt (tong)) : print ("YES")
    else : print ("NO")