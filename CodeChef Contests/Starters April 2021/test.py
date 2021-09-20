<<<<<<< HEAD
from random import randint

def possible(k):
	curr = 0
	

def solve(n, m, a):
	low, high, res = 0, n + 1, -1
	while low <= high:
		mid = (low + high) / 2
		if possible(mid):
			res = mid
			high = mid - 1
		else:
			low = mid + 1
	return res

inputFile = open('input.in', 'w')
outputFile = open('output.txt', 'w')

t = 100
inputFile.write(f'{t}\n')
for _ in range(t):
	n = randint(1, 100)
	m = randint(1, 100)
	inputFile.write(f'{n} {m}\n')
	a = [0] * m
	for _ in range(m):
		l = randint(1, n - 1)
		r = randint(l + 1, n)
		a[_] = (l, r)
		inputFile.write(f'{l} {r}\n')
	a.sort()
	outputFile.write(f'{solve(n, m, a)}\n')

inputFile.close()
=======
from random import randint

def possible(k):
	curr = 0
	

def solve(n, m, a):
	low, high, res = 0, n + 1, -1
	while low <= high:
		mid = (low + high) / 2
		if possible(mid):
			res = mid
			high = mid - 1
		else:
			low = mid + 1
	return res

inputFile = open('input.in', 'w')
outputFile = open('output.txt', 'w')

t = 100
inputFile.write(f'{t}\n')
for _ in range(t):
	n = randint(1, 100)
	m = randint(1, 100)
	inputFile.write(f'{n} {m}\n')
	a = [0] * m
	for _ in range(m):
		l = randint(1, n - 1)
		r = randint(l + 1, n)
		a[_] = (l, r)
		inputFile.write(f'{l} {r}\n')
	a.sort()
	outputFile.write(f'{solve(n, m, a)}\n')

inputFile.close()
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
outputFile.close()