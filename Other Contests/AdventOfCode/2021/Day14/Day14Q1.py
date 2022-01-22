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

x = data[0]
m = [l.split(' -> ') for l in data[2:]]
m = {i[0]: i[0][0] + i[1] for i in m}

j = 0
while j < 10:
	n = ''
	for i in range(1, len(x)):
		if x[i - 1] + x[i] in m:
			n += m[x[i - 1] + x[i]]
			i += 1
		else:
			n += x[i - 1]
		i += 1
	n += x[-1]
	x = n
	j += 1

freq = {}
for i in x:
	if i not in freq:
		freq[i] = 0
	freq[i] += 1

res = max(freq.values()) - min(freq.values())

print(res)
# submit(res, part = 'a', day = 14, year = 2021)
