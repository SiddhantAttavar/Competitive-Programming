for _ in range(int(input())):
	n, k = map(int, input().split())
	p = input()
	q = input()

	a = [[0] * k, [0] * k]
	b = [[0] * k, [0] * k]

	for i in range(n):
		a[ord(p[i]) - ord('0')][i % k] += 1
		b[ord(q[i]) - ord('0')][i % k] += 1
	
	if a == b:
		print('YES')
	else:
		print('NO')
