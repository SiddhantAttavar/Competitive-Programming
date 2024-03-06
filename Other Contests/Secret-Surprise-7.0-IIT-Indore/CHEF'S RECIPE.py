n = int(input())
a = list(map(int, input().split()))
r = list(map(int, input().split()))
res = int(1e9)
for i in range(n):
	if r[i]:
		res = min(res, a[i] // r[i])
print(res)
