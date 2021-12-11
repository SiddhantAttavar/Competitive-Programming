from aocd import get_data, submit
data = get_data(day = 9, year = 2021).splitlines()

def dfs(i, j):
	if a[i][j] == 100 or a[i][j] == 9:
		return 0

	if visited[i][j]:
		return 0
	
	visited[i][j] = True
	ans = 1
	for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
		ans += dfs(x, y)
	
	return ans

a = [[100] * (len(data[0]) + 2) for i in range(len(data) + 2)]
for i in range(1, 101):
	for j in range(1, 101):
		a[i][j] = int(data[i - 1][j - 1])

visited = [[False] * len(a[i]) for i in range(len(a))]
res = []
for i in range(len(a)):
	for j in range(len(a[i])):
		if not visited[i][j] and a[i][j] not in {9, 100}:
			x = dfs(i, j)
			res.append(x)
res.sort()

print(res[-3] * res[-2] * res[-1])
# submit(res[-3] * res[-2] * res[-1], part = 'b', day = 9, year = 2021)
