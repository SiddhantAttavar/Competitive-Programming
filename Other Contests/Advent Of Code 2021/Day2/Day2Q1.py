inputFile = open('input.txt', 'r')
x = 0
y = 0
for line in inputFile.read().splitlines():
	a, b = line.split()
	if a[0] == 'f':
		x += int(b)
	elif a[0] == 'u':
		y -= int(b)
	elif a[0] == 'd':
		y += int(b)
print(x * y)
inputFile.close()
