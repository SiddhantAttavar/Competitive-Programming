from aocd import get_data, submit
data = get_data(day = 2, year = 2021).splitlines()
# data = '''forward 5
# down 5
# forward 8
# up 3
# down 8
# forward 2'''.splitlines()

x = 0
y = 0
for line in data:
	a, b = line.split()
	if a[0] == 'f':
		x += int(b)
	elif a[0] == 'u':
		y -= int(b)
	elif a[0] == 'd':
		y += int(b)

print(x * y)
# submit(x * y, part = 'a', day = 2, year = 2021)

