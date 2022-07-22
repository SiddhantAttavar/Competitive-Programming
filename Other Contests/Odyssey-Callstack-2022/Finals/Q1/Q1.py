from math import gcd

for _ in range(int(input())):
	x, y = map(int, input().split())
	if x * y // gcd(x, y) % (x & y) == 0:
		print('YES')
	else:
		print('NO')
