class Comparator(tuple):
	def __lt__(self, other):
		ax = self[2] - self[0]
		ay = self[3] - self[1]
		bx = other[2] - other[0]
		by = other[3] - other[1]

		at = (ay * bx, bx * (ax * self[1] - ay * self[0]), self[0])
		bt = (by * ax, ax * (bx * other[1] - by * other[0]), other[0])

		return at < bt

for _ in range(int(input())):
	n = int(input())

	v = sorted([tuple(map(int, input().split())) for _ in range(n)], key = Comparator)

	x, y = 0, 0
	p, q = 1, 1
	for i in range(1, n):
		ax = v[i][2] - v[i][0]
		ay = v[i][3] - v[i][1]
		bx = v[i - 1][2] - v[i - 1][0]
		by = v[i - 1][3] - v[i - 1][1]

		at = (ay * bx, bx * (ax * v[i][1] - ay * v[i][0]), v[i][0])
		bt = (by * ax, ax * (bx * v[i - 1][1] - by * v[i - 1][0]), v[i - 1][0])

		if at[0] == bt[0]:
			p += 1

			if (at[1] == bt[1]) and (ax != 0 or bx != 0 or at[2] == bt[2]):
				q += 1
			else:
				y += q * (q - 1) // 2
				q = 1
		else:
			x += p * (p - 1) // 2
			p = 1

			y += q * (q - 1) // 2
			q = 1
	
	x += p * (p - 1) // 2
	y += q * (q - 1) // 2

	# print(x, y)
	print(n * (n - 1) // 2 - x + y)
