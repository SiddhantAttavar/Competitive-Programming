for _ in range(int(input())):
	n, e = map(int, input().split())
	r = list(map(int, input().split()))
	s = set()

	for i in r:
		u = 1

		x = 60
		for j in range(29, -1, -1):
			if (1 << j) & i:
				x = j - 1
				break

		for j in range(x, -1, -1):
			u <<= 1
			if (1 << j) & i:
				u += 1
			s.add(u)
	
	print(len(s))
