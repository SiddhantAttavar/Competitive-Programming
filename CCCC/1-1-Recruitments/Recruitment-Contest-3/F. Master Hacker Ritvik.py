n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ind = [0] * n
for i in range(n):
	ind[a[i] - 1] = i

x = [ind[i - 1] for i in b]
# print(x)

j = n - 1
c = 1
for i in range(n - 2, -1, -1):
	if x[i] < x[j]:
		j = i
		c += 1

print(n - c)
