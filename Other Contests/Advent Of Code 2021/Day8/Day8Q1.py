inputFile = inputFile = open('input.txt', 'r')
data = inputFile.read().splitlines()

res = 0
for line in data:
	a, b = line.split('|')
	x = a.split(' ')
	y = b.split(' ')

	for num in y:
		if len(num) in {2, 4, 3, 7}:
			res += 1

print(res)

inputFile.close()
