fib = [0, 1]
for i in range(2, int(input()) + 1):
    fib.append(fib[-1] + fib[-2])

print(*fib, sep = ',')