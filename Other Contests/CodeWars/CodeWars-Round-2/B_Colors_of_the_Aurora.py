for _ in range(int(input())):
	n = int(input())
	dp = [[0, 0, 0] for _ in range(n + 1)]
	dp[0][2] = 1
	MOD = int(1e9) + 7
	for i in range(1, n + 1):
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % MOD
	print(dp[-1][-1])
