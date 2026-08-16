for _ in range(int(input())):
    s = input()
    n = len(s)
    ok = True
    for i in range(1, n):
        if abs(ord(s[i]) - ord(s[i - 1])) != abs(ord(s[n - i]) - ord(s[n - i - 1])):
            ok = False
            break
    print("YES" if ok else "NO")