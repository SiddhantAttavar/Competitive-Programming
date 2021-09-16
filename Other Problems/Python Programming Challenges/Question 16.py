l = map(int, input().split(','))
res = [i for i in l if i % 2 == 1]
print(*res, sep = ',')