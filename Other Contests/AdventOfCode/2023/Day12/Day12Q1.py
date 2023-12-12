from aocd import get_data, submit
data = get_data(day = 12, year = 2023).splitlines()
# data = '''???.### 1,1,3
# .??..??...?##. 1,1,3
# ?#?#?#?#?#?#?#? 1,3,1,6
# ????.#...#... 4,1,1
# ????.######..#####. 1,6,5
# ?###???????? 3,2,1'''.splitlines()

def check(s, l):
	# print(''.join(s), l)
	v = [0]
	for i in s:
		if i == '.':
			if v[-1] != 0:
				v.append(0)
		else:
			v[-1] += 1
	
	if v[-1] == 0:
		v.pop()
	# print(v)
	return v == l

def solve(s, l):
	s = list(s)
	v = []
	for i in range(len(s)):
		if s[i] == '?':
			v.append(i)

	res = 0
	for i in range(1 << len(v)):
		t = s.copy()
		for j in range(len(v)):
			if i & (1 << j):
				t[v[j]] = '#'
			else:
				t[v[j]] = '.'
		res += check(t, l)

	return res

res = 0
for i, r in enumerate(data):
	s, l = r.split()
	# print(i)
	res += solve(s, list(map(int, l.split(','))))
	# break

print(res)
submit(res, part = 'a', day = 12, year = 2023)
