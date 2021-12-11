from aocd import get_data, submit
data = get_data(day = 2, year = 2021).splitlines()

x = 0
y = 0
aim = 0
for line in data:
	a, b = line.split()
	if a[0] == 'f':
		x += int(b)
		y += aim * int(b)
	elif a[0] == 'u':
		aim -= int(b)
	elif a[0] == 'd':
		aim += int(b)

print(x * y)
# submit(x * y, part = 'b', day = 2, year = 2021)
