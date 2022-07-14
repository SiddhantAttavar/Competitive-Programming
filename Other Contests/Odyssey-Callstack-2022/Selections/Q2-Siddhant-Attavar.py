for _ in range(int(input())):
	n = int(input())
	s = input()
	i = 0
	c = 0
	while i < n:
		if s[i] == '.':
			c += 1
			i += 3
		else:
			i += 1
	print(c)
