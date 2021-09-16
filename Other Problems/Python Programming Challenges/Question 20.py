def generator(n):
    for i in range(0, n, 7):
        yield i

for i in generator(100):
    print(i)