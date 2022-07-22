n, p = map(int, input().split())
s = list(map(int, input().split()))
res = 0
for i in range(1 << n):
	c = 0
	for j in range(n):
		if i & (1 << j):
			c += s[j]
	print(c)
	res += c >= p
	res %= (int(1e9) + 7)
print(res)
