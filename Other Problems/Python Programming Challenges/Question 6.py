from math import sqrt

c = 50
h = 30
l = list(map(lambda x: round(float(x)), input().split(',')))

res = []
for d in l:
    res.append(round(sqrt(2 * c * d / h)))
print(*res, sep = ',')