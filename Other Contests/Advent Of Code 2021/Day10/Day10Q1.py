inputFile = inputFile = open('input.txt', 'r')
data = inputFile.read().splitlines()

score = {
	')': 3,
	']': 57,
	'}': 1197,
	'>': 25137
}

match = {
	')': '(',
	']': '[',
	'}': '{',
	'>': '<'
}

res = 0
for j, l in enumerate(data):
	curr = []
	for i, c in enumerate(l):
		if c in score:
			if not curr or curr.pop() != match[c]:
				res += score[c]
				break
		else:
			curr.append(c)

print(res)

inputFile.close()
