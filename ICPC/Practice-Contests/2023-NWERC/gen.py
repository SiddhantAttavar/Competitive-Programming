from random import randint
t = 1000
print(t)
for _ in range(t):
    n = randint(2, 100000)
    k = randint(1, n - 1)
    print(n, k)
