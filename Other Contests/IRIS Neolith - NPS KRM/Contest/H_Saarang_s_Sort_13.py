for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if sorted(a) == a:
        print(0)
    elif a[0] == 1 or a[-1] == n:
        print(1)
    else:
        if a[0] == n and a[-1] == 1:
            print(3)
        else:
            print(2)
