from aocd import get_data, submit
data = get_data(day = 6, year = 2021).splitlines()
# data = '''3,4,3,1,2'''.splitlines()

l = list(map(int, data[0].split(',')))
for _ in range(80):
	a = []
	for i in l:
		if i == 0:
			a.append(6)
			a.append(8)
		else:
			a.append(i - 1)
	l = a

print(len(l))
# submit(len(l), part = 'a', day = 6, year = 2021)
