from aocd import get_data, submit
data = get_data(day = 14, year = 2021).splitlines()
# data = '''NNCB

# CH -> B
# HH -> N
# CB -> H
# NH -> C
# HB -> C
# HC -> B
# HN -> C
# NN -> C
# BH -> H
# NC -> B
# NB -> B
# BN -> B
# BB -> N
# BC -> B
# CC -> N
# CN -> C'''.splitlines()

from collections import defaultdict

q = data[0]
q = [ord(i) - ord('A') for i in q]
m = [l.split(' -> ') for l in data[2:]]

d = [[-1] * 26 for _ in range(26)]
for x, y in m:
	a = ord(x[0]) - ord('A')
	b = ord(x[1]) - ord('A')
	c = ord(y) - ord('A')

	d[a][b] = c

dp = [[[defaultdict(lambda: 0) for k in range(26)] for j in range(26)] for i in range(40)]
for i in range(26):
	for j in range(26):
		dp[0][i][j][i] = 1
		dp[0][i][j][j] += 1
		if d[i][j] != -1:
			dp[0][i][j][d[i][j]] += 1

for s in range(1, 40):
	for i in range(26):
		for j in range(26):
			if d[i][j] != -1:
				k = d[i][j]
				a = dp[s - 1][i][k]
				b = dp[s - 1][k][j]
				for x, y in list(a.items()) + list(b.items()):
					dp[s][i][j][x] += y
				dp[s][i][j][k] -= 1
			else:
				dp[s][i][j][i] = 1
				dp[s][i][j][j] += 1

fin = defaultdict(lambda: 0)
for i in range(len(q) - 1):
	for x, y in dp[-1][q[i]][q[i + 1]].items():
		fin[x] += y

for i in q[1: -1]:
	fin[i] -= 1

res = max(fin.values()) - min(fin.values())

print(res)
# submit(res, part = 'b', day = 14, year = 2021)
