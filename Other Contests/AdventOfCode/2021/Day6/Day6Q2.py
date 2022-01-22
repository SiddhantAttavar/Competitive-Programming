from aocd import get_data, submit
data = get_data(day = 6, year = 2021).splitlines()
# data = '''3,4,3,1,2'''.splitlines()

from sys import setrecursionlimit
setrecursionlimit(int(1e9))

memo = {}
def solve(i, n):
	if (i, n) in memo:
		return memo[(i, n)]
	if n == 0:
		return 1
	if i == 0:
		memo[i, n] = solve(6, n - 1) + solve(8, n - 1)
		return memo[(i, n)]
	memo[(i, n)] = solve(i - 1, n - 1)
	return memo[(i, n)]

l = list(map(int, data[0].split(',')))
res = 0
for i in l:
	res += solve(i, 256)
	
print(res)
# submit(res, part = 'b', day = 6, year = 2021)
