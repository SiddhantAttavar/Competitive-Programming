def score(i, j):
	s = 0
	for k in range(4):
		s += w[j][k] * e[i][k]
	return s

t = int(input()) - 1

w = []
for i in range(4):
	w.append(list(map(float, input().split())))

e = []
for i in range(20):
	e.append(list(map(int, input().split())))

l = [sorted(range(20), key = lambda i: score(i, j), reverse = True) for j in range(4)]

p = set(range(20))
c = [0] * 4
res = [[] for _ in range(4)]
for i in range(5):
	for j in range(4):
		while l[j][c[j]] not in p:
			c[j] += 1
		res[j].append(l[j][c[j]] + 1)
		p.remove(l[j][c[j]])

print(*res[t])
