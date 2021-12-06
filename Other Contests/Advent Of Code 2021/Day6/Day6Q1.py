inputFile = open('input.txt', 'r')
l = list(map(int, inputFile.read().splitlines()[0].split(',')))
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
inputFile.close()
