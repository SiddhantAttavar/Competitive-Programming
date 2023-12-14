from aocd import get_data, submit
from functools import lru_cache
data = get_data(day = 12, year = 2023).splitlines()
# data = '''???.### 1,1,3
# .??..??...?##. 1,1,3
# ?#?#?#?#?#?#?#? 1,3,1,6
# ????.#...#... 4,1,1
# ????.######..#####. 1,6,5
# ?###???????? 3,2,1'''.splitlines()

@lru_cache(maxsize = 10000)
def solve(s, l, i, j):
	# print('debug', s, l, i, j)
	if j < 0:
		return i < 0 or ('#' not in s[:i + 1])

	if i < 0:
		return 0
	
	res = 0
	for k in range(i, l[j] - 2, -1):
		if '.' not in s[k - l[j] + 1: k + 1] and (k < l[j] or s[k - l[j]] != '#'):
			res += solve(s, l, k - l[j] - 1, j - 1)
		if s[k] == '#':
			return res
	
	return res

res = 0
for i, r in enumerate(data):
	s, l = r.split()
	s = '?'.join([s] * 5)
	l = tuple(list(map(int, l.split(','))) * 5)
	# l = tuple(list(map(int, l.split(','))))
	# print(i)
	res += solve(s, l, len(s) - 1, len(l) - 1)
	# break

print(res)
submit(res, part = 'b', day = 12, year = 2023)
