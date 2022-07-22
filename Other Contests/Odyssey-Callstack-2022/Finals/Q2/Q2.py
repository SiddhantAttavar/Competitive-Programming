n = int(input())

l = [list(map(int, input().split())) for _ in range(n)]
l.sort()

res = []
flag = False
c = -1
for i in range(len(l)):
	c = max(c, l[i][1])
	if not flag:
		res.append([l[i][0], c])
	else:
		res[-1][1] = c
	flag = i < len(l) - 1 and c >= l[i + 1][0]

for x, y in res:
	print(x, y)
