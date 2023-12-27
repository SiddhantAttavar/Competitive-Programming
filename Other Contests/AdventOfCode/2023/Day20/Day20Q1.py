from collections import defaultdict
from queue import Queue
from aocd import get_data, submit
data = get_data(day = 20, year = 2023).splitlines()
# data = '''broadcaster -> a, b, c
# %a -> b
# %b -> c
# %c -> inv
# &inv -> a'''.splitlines()
# data = '''broadcaster -> a
# %a -> inv, con
# &inv -> b
# %b -> con
# &con -> output'''.splitlines()

res = 0
graph = defaultdict(lambda: [])
rev_graph = defaultdict(lambda: [])
t = defaultdict(lambda: 0)
op = 'b%&'
for s in data:
	a, l = s[1:].split(' -> ')
	graph[a] = l.split(', ')
	t[a] = op.index(s[0])
	for b in graph[a]:
		rev_graph[b].append(a)

ff = defaultdict(lambda: False)
con = defaultdict(lambda: defaultdict(lambda: False))
l = 0
h = 0

con = defaultdict(lambda: defaultdict(lambda: False))
ff = defaultdict(lambda: False)
for _ in range(1000):
	q = Queue()
	q.put(('roadcaster', False, -1))
	while not q.empty():
		u, b, p = q.get()
		# print(u, b, p)

		if b:
			h += 1
		else:
			l += 1

		if u not in graph:
			continue

		x = False
		if t[u] == 0:
			x = b
		elif t[u] == 1:
			if not b:
				ff[u] = not ff[u]
				x = ff[u]
			else:
				continue
		elif t[u] == 2:
			con[u][p] = b
			for i in rev_graph[u]:
				if not con[u][i]:
					x = True
					break

		for v in graph[u]:
			q.put((v, x, u))

# print(l, h)
res = l * h
print(res)
submit(res, part = 'a', day = 20, year = 2023)
