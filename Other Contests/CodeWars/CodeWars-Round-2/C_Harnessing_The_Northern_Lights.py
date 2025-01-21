for _ in range(int(input())):
	n = int(input())
	x = {
		'Winter': 1,
		'Spring': 2,
		'Summer': 3,
		'Autumn': 4
	}[input()]
	vals = [1, x << 1, x << 2, x << 3, x << 4, x << 5]
	res = max(0, n - 250) // vals[-1]
	n -= vals[-1] * res
	dp = {1}
	if n in dp:
		print(res)
	for i in range(50):
		ndp = set()
		for j in vals:
			for k in dp and k + j <= n:
				ndp.add(k + j)
		dp = ndp
		print(dp)
		if n in dp:
			print(i + res + 1)
			break
