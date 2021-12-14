from aocd import get_data, submit
data = get_data(day = 7, year = 2021).splitlines()
# data = '''16,1,2,0,4,2,7,1,2,14'''.splitlines()

l = list(map(int, data[0].split(',')))
res = int(1e10)
for i in range(max(l)):
	c = 0
	for j in l:
		c += abs(i - j)
	res = min(res, c)

print(res)
# submit(res, part = 'a', day = 7, year = 2021)
