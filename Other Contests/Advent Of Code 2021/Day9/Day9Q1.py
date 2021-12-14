from aocd import get_data, submit
data = get_data(day = 9, year = 2021).splitlines()
# data = '''2199943210
# 3987894921
# 9856789892
# 8767896789
# 9899965678'''.splitlines()

a = [[100] * (len(data[0]) + 2) for i in range(len(data) + 2)]
for i in range(100):
	for j in range(100):
		a[i + 1][j + 1] = int(data[i][j])

res = 0
for i in range(1, len(a) - 1):
	for j in range(1, len(a[i]) - 1):
		if a[i][j] < min(a[i - 1][j], a[i + 1][j], a[i][j + 1], a[i][j - 1]):
			res += a[i][j] + 1

print(res)
# submit(res, part = 'a', day = 9, year = 2021)
