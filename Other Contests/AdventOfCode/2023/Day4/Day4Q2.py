from aocd import get_data, submit
data = get_data(day = 4, year = 2023).splitlines()
# data = '''Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
# Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
# Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
# Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
# Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
# Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11'''.splitlines()

# res = 0
l = []
for row in data:
	x, y = row.split(':')[1].split('|')
	a = list(map(int, x.split()))
	b = set(map(int, y.split()))
	# print(a, b)
	c = 0
	d = set()
	for i in a:
		if i in b:
			c += 1
	l.append(c)

# print(l)
dp = l.copy()
pref = [0] * (len(l) + 1)
for i in range(len(l) - 1, -1, -1):
	# print(i, l[i], i + l[i] + 1)
	dp[i] += pref[i + 1] - pref[min(len(l), i + l[i] + 1)]
	pref[i] = pref[i + 1] + dp[i]

# print(dp)
# print(pref)
res = pref[0] + len(l)
print(res)
submit(res, part = 'b', day = 4, year = 2023)
