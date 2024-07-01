for _ in range(int(input())):
	n, x = map(int, input().split())
	a = sorted(map(int, input().split()))
	l = 0
	r = n - 1
	s = sum(a)
	
	p = 0
	q = 0
	for i in range(n - x, n):
		q += a[i]
	res = s - q
	
	j = 0
	for i in range(n - x, n):
		q -= a[i]
		p += a[j] + a[j + 1]
		j += 2
		res = max(res, s - p - q)

	print(res)
