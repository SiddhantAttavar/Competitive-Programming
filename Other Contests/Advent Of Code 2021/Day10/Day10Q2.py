inputFile = inputFile = open('input.txt', 'r')
data = inputFile.read().splitlines()

score = {
	'(': 1,
	'[': 2,
	'{': 3,
	'<': 4
}

match = {
	')': '(',
	']': '[',
	'}': '{',
	'>': '<'
}

res = []
for l in data:
	curr = []
	for c in l:
		if c in score:
			curr.append(c)
		elif not curr or curr.pop() != match[c]:
				break
	else:
		lineScore = 0
		for c in curr[::-1]:
			lineScore *= 5
			lineScore += score[c]
		res.append(lineScore)

res.sort()
if len(res) % 2 == 0:
	print((res[len(res) // 2] + res[len(res) // 2 - 1]) // 2)
else:
	print(res[len(res) // 2])

inputFile.close()
