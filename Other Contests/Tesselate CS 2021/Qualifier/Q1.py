from functools import lru_cache
from math import log2
from sys import setrecursionlimit

setrecursionlimit(int(1e9))

@lru_cache(maxsize = None)
def solve(s, n):
	if n == 0:
		return int(s == 'abc')
	
	return (
		solve(s[1] + s[0] + s[2], n - 1) + 
		solve(s[0] + s[2] + s[1], n - 1)
	)

n = solve('abc', 2022)
print(int(log2(3 * n)))
