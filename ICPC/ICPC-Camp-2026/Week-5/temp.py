from random import randint

n = 1000
a = [randint(1, n) for _ in range(n)]
print(n)
print(*a)
