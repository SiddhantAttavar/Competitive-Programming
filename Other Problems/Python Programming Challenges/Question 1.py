res = []

for i in range(2000, 3001):
    if i % 7 == 0 and i % 5 != 0:
        res.append(i)

print(*res, sep = ',')