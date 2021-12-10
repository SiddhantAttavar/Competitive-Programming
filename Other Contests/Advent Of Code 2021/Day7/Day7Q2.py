from aocd import get_data, submit
data = get_data(day = 7, year = 2021).splitlines()

l = list(map(int, data[0].split(',')))
res = int(1e10)
for i in range(max(l) + 1):
	c = 0
	for j in l:
		c += abs(i - j) * (abs(i - j) + 1) // 2
	res = min(res, c)

print(res)
#submit(res, part = 'b', day = 7, year = 2021)
