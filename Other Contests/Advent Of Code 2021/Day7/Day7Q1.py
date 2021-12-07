inputFile = inputFile = open('input.txt', 'r')
l = list(map(int, inputFile.read().splitlines()[0].split(',')))
res = int(1e10)
for i in range(max(l)):
	c = 0
	for j in l:
		c += abs(i - j)
	res = min(res, c)
print(res)
inputFile.close()
