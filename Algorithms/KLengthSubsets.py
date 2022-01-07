a = tuple(map(int, input().split()))
k = int(input())

# Method 1
print('Method 1')
from itertools import combinations
for subset in combinations(a, k):
	print(*subset)

# Method 2
print('Method 2')
from functools import lru_cache

@lru_cache(maxsize = None)
def genSubsets(a, k):
	if k == 0 or len(a) == 0 or k > len(a):
		return []
    
	if k == 1:
		return [[i] for i in a]

	x = genSubsets(a[1:], k - 1)
	y = genSubsets(a[1:], k)
	for i in range(len(x)):
		x[i] = [a[0]] + x[i]

	return x + y

for subset in genSubsets(a, k):
	print(*subset)
