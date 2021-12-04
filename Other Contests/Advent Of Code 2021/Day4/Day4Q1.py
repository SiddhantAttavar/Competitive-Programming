def checkWin(l, m):
	a = [[l[i][j] in m for j in range(5)] for i in range(5)]
	b = [[a[j][i] for j in range(5)] for i in range(5)]
	for i in range(5):
		if sum(a[i]) == 5 or sum(b[i]) == 5:
			return True
	return False

inputFile = open('input.txt', 'r')
data = inputFile.read().splitlines()

moves = map(int, data[0].split(','))
boards = []
for l in data[1:]:
	if not l:
		boards.append([])
		continue
	boards[-1].append(list(map(int, l.split())))

m = set()
res = -1
for move in moves:
	m.add(move)
	nextBoards = []
	for board in boards:
		if checkWin(board, m):
			res = 0
			for i in board:
				for j in i:
					if j not in m:
						res += j
			res *= move
			break
	if res != -1:
		break
print(res)
inputFile.close()
