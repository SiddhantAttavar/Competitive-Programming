from aocd import get_data, submit
data = get_data(day = 8, year = 2021).splitlines()

res = 0
for line in data:
	a, b = line.split('|')
	x = a.split(' ')
	y = b.split(' ')

	for num in y:
		if len(num) in {2, 4, 3, 7}:
			res += 1

print(res)
# submit(res, part = 'a', day = 8, year = 2021)
