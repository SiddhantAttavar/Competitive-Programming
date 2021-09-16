def evenGenerator(n):
    for i in range(0, n + 1, 2):
        yield i

print(*evenGenerator(int(input())), sep = ',')