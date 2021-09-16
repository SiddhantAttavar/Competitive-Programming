for _ in range(int(input())):
    n = int(input())
    x = 0
    while n:
        x += 1
        n //= 10
    print(x)