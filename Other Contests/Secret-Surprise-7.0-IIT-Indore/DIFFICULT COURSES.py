for _ in range(int(input())):
	n = int(input())
	print(*[(1 << (i + 1)) - 1 for i in range(n)])
