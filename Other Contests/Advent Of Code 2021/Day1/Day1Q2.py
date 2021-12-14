from aocd import get_data, submit
data = get_data(day = 1, year = 2021).splitlines()
# data = '''199
# 200
# 208
# 210
# 200
# 207
# 240
# 269
# 260
# 263'''.splitlines()

l = list(map(int, data))
res = 0
s = sum(l[:3])
for i in range(3, len(l)):
	n = s + l[i] - l[i - 3]
	if n > s:
		res += 1

print(res)
# submit(res, part = 'b', day = 1, year = 2021)
