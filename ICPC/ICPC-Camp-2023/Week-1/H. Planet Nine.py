from math import *
from collections import *
arrPut = lambda: list(map(int, input().split()))

a, b = map(int, input().split())
x = ((a - b) % 9 + 9) % 9
s = str(b)
s = '1' * x + s

k = int(s)

print('Stable')
print(((k - a) > 0) + (x > 0))
if (k - a) > 0:
	print('+', (k - a) // 9)
if x > 0:
	print('-', x)
