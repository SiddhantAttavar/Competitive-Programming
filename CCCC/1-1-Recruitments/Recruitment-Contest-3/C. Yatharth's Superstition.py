for _ in range(int(input())):
	n, m, k = map(int, input().split())
	a, b = sorted(input()), sorted(input())
	i = j = x = y = 0
	c = ''
	while i < n and j < m:
		if j < m and y < k and (i == n or x == k or b[j] < a[i]):
			# print(i, j, x, y)
			c += b[j]
			j += 1
			y += 1
			x = 0
		elif x < k:
			c += a[i]
			i += 1
			x += 1
			y = 0
		else:
			break
	print(c)
