n = int(input())
res = 0
for i in range(1, n + 1):
    res += i / (i + 1)
print(res)