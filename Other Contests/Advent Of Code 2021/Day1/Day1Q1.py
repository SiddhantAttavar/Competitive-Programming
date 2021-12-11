from aocd import get_data, submit
data = get_data(day = 1, year = 2021).splitlines()

l = list(map(int, data))
res = 0
for i in range(1, len(l)):
	if l[i] > l[i-1]:
		res += 1

print(res)
# submit(res, part = 'a', day = 1, year = 2021)
