n = int(input())
dp = [1] * n
for i in range(n - 2, -1, -1):
	dp[i] = dp[i + 1]
	for j in range(i + 1, n):
		# print(i, j)
		if (j + 1) % (i + 1) == 0:
			dp[i] += 1
print(dp[0])
