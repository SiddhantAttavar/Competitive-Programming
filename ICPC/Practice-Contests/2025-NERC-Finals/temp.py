from random import randint
n = 100000
k = 30
print(n, k)
print(*[randint(0, 100) for _ in range(n)])
