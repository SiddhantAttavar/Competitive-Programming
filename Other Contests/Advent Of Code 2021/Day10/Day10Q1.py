from aocd import get_data, submit
data = get_data(day = 10, year = 2021).splitlines()

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
#submit(res, part = 'a', day = 10, year = 2021)
