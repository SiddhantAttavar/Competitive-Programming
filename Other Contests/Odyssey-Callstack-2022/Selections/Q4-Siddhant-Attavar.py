n = int(input())
dp1 = [0] * (n + 1)
dp2 = [0] * (n + 1)
dp1[0] = 1

for i in range(1, n + 1):
	dp1[i] = dp1[i - 1]
	if i >= 3:
		dp1[i] += dp1[i - 3]
		if i >= 4:
			dp1[i] += 2 * dp2[i - 4]

	dp2[i] = dp1[i - 2]

print(dp1[n])
