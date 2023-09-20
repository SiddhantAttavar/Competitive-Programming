MOD = int(1e9 + 7)

def solve(n, l, r):
	# print(n, l, r)
	if n == 1:
		return 1

	if r < l:
		return 0

	m = n // 2
	if r <= m:
		return (2 * solve(m, l, r) - (r - l + 1)) % MOD
	
	if l > m:
		return (2 * solve(m, l - m, r - m)) % MOD

	x = m * (m + 1) // 2
	if r - m < l:
		return (2 * (x - solve(m, r - m + 1, l - 1)) - (m - l + 1)) % MOD
	return (2 * (x + solve(m, l, r - m)) - (m - l + 1)) % MOD

for _ in range(int(input())):
	print(solve(*map(int, input().split())))
