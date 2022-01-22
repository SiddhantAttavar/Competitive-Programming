from aocd import get_data, submit
data = get_data(day = 4, year = 2021).splitlines()
# data = '''7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1

# 22 13 17 11  0
#  8  2 23  4 24
# 21  9 14 16  7
#  6 10  3 18  5
#  1 12 20 15 19

#  3 15  0  2 22
#  9 18 13 17  5
# 19  8  7 25 23
# 20 11 10 24  4
# 14 21 16 12  6

# 14 21 17 24  4
# 10 16 15  9 19
# 18  8 23 26 20
# 22 11 13  6  5
#  2  0 12  3  7'''.splitlines()

def checkWin(l, m):
	a = [[l[i][j] in m for j in range(5)] for i in range(5)]
	b = [[a[j][i] for j in range(5)] for i in range(5)]
	for i in range(5):
		if sum(a[i]) == 5 or sum(b[i]) == 5:
			return True
	return False

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
		if not checkWin(board, m):
			nextBoards.append(board)
	if len(nextBoards) == 0:
		res = 0
		for i in boards[0]:
			for j in i:
				if j not in m:
					res += j
		res *= move
		break
	boards = nextBoards

print(res)
# submit(res, part = 'b', day = 4, year = 2021)
