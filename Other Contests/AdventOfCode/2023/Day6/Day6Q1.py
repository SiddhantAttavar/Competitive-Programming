from math import ceil, sqrt
from aocd import get_data, submit
data = get_data(day = 6, year = 2023).splitlines()
# data = '''Time:      7  15   30
# Distance:  9  40  200'''.splitlines()

res = 1
t = list(map(int, data[0].split()[1:]))
d = list(map(int, data[1].split()[1:]))
for i, j in zip(t, d):
	l = 1
	r = i // 2
	x = -1
	while l <= r:
		m = (l + r) // 2
		if m * (i - m) > j:
			x = m
			r = m - 1
		else:
			l = m + 1

	# print(x)

	if x == -1:
		res = 0
		break

	res *= i - 2 * x + 1
	# print(res)

print(res)
# submit(res, part = 'a', day = 6, year = 2023)
