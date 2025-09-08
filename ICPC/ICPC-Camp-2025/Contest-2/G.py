from decimal import Decimal
from math import factorial
n, k = map(int, input().split())
s = list(map(Decimal, input().split()))

x = Decimal(factorial(n)) / Decimal(factorial(n - k) * k)
fact = [Decimal(factorial(n - l - 1)) / Decimal(x * factorial(n - k - l)) for l in range(n - k + 1)]
for i in range(n):
	c = Decimal(0)
	for l in range(n - k + 1):
		j = (i - l + n) % n
		c += s[j] * fact[l]
	print(f'{c:.10f}', end = ' ')
