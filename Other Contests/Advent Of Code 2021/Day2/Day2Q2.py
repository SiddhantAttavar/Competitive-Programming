inputFile = open('input.txt', 'r')
x = 0
y = 0
aim = 0
for line in inputFile.read().splitlines():
	a, b = line.split()
	if a[0] == 'f':
		x += int(b)
		y += aim * int(b)
	elif a[0] == 'u':
		aim -= int(b)
	elif a[0] == 'd':
		aim += int(b)
print(x * y)
