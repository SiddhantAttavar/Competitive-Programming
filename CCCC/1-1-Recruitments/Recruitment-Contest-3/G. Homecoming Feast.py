from bisect import bisect

n, m = map(int, input().split())
x, k, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = [False] * n
j = 0
for i in range(n):
	if j < m and a[i] == b[j]:
		c[i] = True
		j += 1

if j < m:
	print(-1)
	exit()

pref = [0] * (n + 1)
for i in range(n):
	pref[i + 1] = pref[i] + c[i]

dp = [int(1e18)] * n
p = 0
v = []
for i in range(n):
	if c[i]:
		p = a[i]
		if len(v) == 0:
			if i == 0:
				dp[i] = 0
			else:
				dp[i] = dp[i - 1]
			continue

		if a[i] < max(v):
			print(-1)
			exit()

		if i == len(v):
			dp[i] = y * len(v)
		else:
			dp[i] = min(dp[i], dp[i - len(v)] + y * len(v))

		if dp[i] == int(1e18):
			print(-1)
			exit()

		v = []
	else:
		if i >= k and pref[i + 1] == pref[i - k + 1]:
			dp[i] = min(dp[i], dp[i - k] + x)
		elif i == k - 1 and pref[k] == 0:
			dp[i] = x

		if p > a[i]:
			dp[i] = min(dp[i], dp[i - 1] + y)
		
		if dp[i] == int(1e18):
			v.append(a[i])
		else:
			v = []

# print(dp)

if dp[n - 1] == int(1e18):
	print(-1)
else:
	print(dp[n - 1])
