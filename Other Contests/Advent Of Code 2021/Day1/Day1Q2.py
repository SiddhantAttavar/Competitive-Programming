inputFile = open('input.txt', 'r')
l = list(map(int, inputFile.read().splitlines()))
res = 0
s = sum(l[:3])
for i in range(3, len(l)):
	n = s + l[i] - l[i - 3]
	if n > s:
		res += 1
print(res)
