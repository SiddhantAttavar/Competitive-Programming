from collections import deque

for _ in range(int(input())):
	q = int(input())
	n, m = map(int, input().split())

	graph = [[] for _ in range(n)]
	for _ in range(m):
		u, v = map(int, input().split())
		graph[u - 1].append(v - 1)
		graph[v - 1].append(u - 1)
	
	cc = []
	v = [False] * n
	qu = deque()
	s = set()

	for i in range(n):
		s.add(i)
	
	for i in range(n):
		if v[i] or i not in s:
			continue
		
		cc.append(1)
		s.remove(i)
		v[i] = True
		qu.append(i)

		while len(qu):
			u = qu.popleft()

			if q == 0:
				for j in graph[u]:
					if v[j]:
						continue

					cc[-1] += 1
					v[j] = True
					qu.append(j)
			else:
				ns = set()
				for j in s:
					if j in graph[i]:
						ns.add(j)
						continue

					cc[-1] += 1
					qu.append(j)
				s = ns
	
	t = set(cc)

	x = 0
	for i in cc:
		x ^= i

	res = x
	for i in t:
		res = max(res, x ^ i)
		for j in t:
			res = max(res, x ^ i ^ j)
			for k in t:
				res = max(res, x ^ i ^ j ^ k)
	
	print(res)
