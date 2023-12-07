from aocd import get_data, submit
data = get_data(day = 7, year = 2023).splitlines()
# data = '''32T3K 765
# T55J5 684
# KK677 28
# KTJJT 220
# QQQJA 483'''.splitlines()

s = 'J23456789TJQKA'
d = {c: i + 1 for i, c in enumerate(s)}

def score(s):
	res = 0
	for i in s:
		res = 14 * res + d[i]

	m = {}
	for i in s:
		m[i] = m.get(i, 0) + 1
	
	l = sorted(m.items(), key = lambda x: x[1])
	i = 0

	res *= 14
	if len(l) == 5:
		return (1, res)
	if len(l) == 4:
		return (2, res)
	if len(l) == 3:
		if l[1][1] == 2:
			return (3, res)
		return (4, res)
	if len(l) == 2:
		if l[0][1] == 2:
			return (5, res)
		return (6, res)
	return (7, res)


l = sorted([list(i.split()) for i in data], key = lambda x: score(x[0]))
res = sum([(i + 1) * int(j[1]) for i, j in enumerate(l)])

print(res)
# submit(res, part = 'a', day = 7, year = 2023)
