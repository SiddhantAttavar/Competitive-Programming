from random import randint
t = 100
print(t)
for i in range(t):
	n = 1000
	print(n)
	a = [randint(-int(1e9), int(1e9)) for i in range(n)]
	print(*sorted(a))