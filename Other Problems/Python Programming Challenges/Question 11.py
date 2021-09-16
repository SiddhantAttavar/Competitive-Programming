words = input().split(',')
res = [i for i in words if int(i, 2) % 5 == 0]
print(*res, sep = ',')