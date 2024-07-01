for _ in range(int(input())):
	s = input()    
	n = len(s)

	c = n - 1
	v = []
	x = 0
	for i in range(n - 1, -1, -1):
		if s[i] == '1':
			if i < c:
				v.append((c - i, x))
			c -= 1
		elif i == n - 1 or s[i + 1] == '1':
			x += 1
	
	res = 0
	for i, j in v:
		res += i + j
	print(res)
