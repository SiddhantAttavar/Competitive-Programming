for _ in range(int(input())):
	n, k = map(int, input().split())
	l = list(map(int, input().split()))
	a = [(l[i] - 1, i) for i in range(n)]
	a.sort()

	l, r = 0, n - 1
	res = [-1] * k
	visited = [False] * n
	for c, i in a:
		if res[c] == -1:
			res[c] = r - l + 1

		visited[i] = True

		while l < n and visited[l]:
			l += 1
		while r >= 0 and visited[r]:
			r -= 1
	
	for i in range(n):
		if res[i] == -1:
			res[i] = 0
		else:
			res[i] *= 2
	
	print(*res)

