inputFile = open('input.txt', 'r')
l = list(map(int, inputFile.read().splitlines()))
res = 0
for i in range(1, len(l)):
	if l[i] > l[i-1]:
		res += 1
print(res)
inputFile.close()
