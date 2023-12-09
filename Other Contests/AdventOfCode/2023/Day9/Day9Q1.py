from aocd import get_data, submit
data = get_data(day = 9, year = 2023).splitlines()
# data = '''0 3 6 9 12 15
# 1 3 6 10 15 21
# 10 13 16 21 30 45'''.splitlines()

def solve(a):
	if sum(a) == 0:
		return 0

	b = [a[i] - a[i - 1] for i in range(1, len(a))]
	return a[-1] + solve(b)

res = 0
l = [list(map(int, i.split())) for i in data]
for i in l:
	res += solve(i)

print(res)
submit(res, part = 'a', day = 9, year = 2023)
