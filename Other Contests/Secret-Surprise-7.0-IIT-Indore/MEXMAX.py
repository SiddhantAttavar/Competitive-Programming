n = int(input())
a = [list(map(int, input().split()))[1:] for _ in range(n)]
b = []
for i in a:
	x = set(i)
	if len(x) == len(i) or max(x) < n:
		c = 0
		for j in x:
			c += 1 << j
		b.append(c)

# print(b)
res = 0
for i in range(1, 1 << len(b)):
	x = 0
	flag = True
	for j in range(len(b)):
		if (1 << j) & i:
			if x & b[j]:
				flag = False
				break

			x |= b[j]
	
	if not flag:
		continue

	h = 0
	while 1 << h <= x:
		h += 1
	# print(x)
	res += x == (1 << h) - 1

print(res)
