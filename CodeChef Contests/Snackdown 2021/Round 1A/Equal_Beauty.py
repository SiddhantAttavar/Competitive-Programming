for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	res = int(2e9)
	for i in range(n - 1):
		res = min(res, abs((a[i] - a[0]) - (a[n - 1] - a[i + 1])))
	for i in range(1, n - 1):
		for j in range(1, i):
			res = min(res, abs((a[i] - a[0]) - (a[n - 1] - a[j])))
	print(res)