for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	c = 0

	b = []
	for i in range(1, n):
		if a[i] == a[i - 1]:
			c += 1
		else:
			b.append(a[i])
	
	if len(b) < 2:
		print(c)
		continue
	
	d = b[0] < b[1]
	x = 0
	for i in range(2, len(b)):
		if (b[i - 1] < b[i]) != d:
			d = not d
		else:
			x += 1
	print(c + len(b) - x - 2)
