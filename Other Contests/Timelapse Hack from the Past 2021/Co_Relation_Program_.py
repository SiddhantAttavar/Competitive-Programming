from math import sqrt, floor
n = int(input())
x, y = [], []
for _ in range(n):
    input()
    x.append(float(input()))
    y.append(float(input()))

sumXY = sum(x[i] * y[i] for i in range(n))
sumX = sum(x)
sumY = sum(y)
sumX2 = sum(x[i] * x[i] for i in range(n))
sumY2 = sum(y[i] * y[i] for i in range(n))
res = (n * sumXY - sumX * sumY) / sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY))

print(f'{floor(res * 100) / 100:.2f}')