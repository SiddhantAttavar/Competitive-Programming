from functools import lru_cache
from sys import setrecursionlimit

setrecursionlimit(int(1e9))

d = {}

@lru_cache(maxsize = None)
def solve(h, x):
	# print(h, x)
	if h == 1:
		return 0
	
	if h == 2:
		return 1

	if x == 1:
		return h - 1
	
	res = int(1e9)
	nm = 0
	for a in range(1, h):
		n = 1 + max(solve(a, x - 1), solve(h - a, x))
		if n < res:
			nm = a
		res = min(
			res,
			n
		)

	d[h, x] = nm

	return res

print(solve(2021, 3))
