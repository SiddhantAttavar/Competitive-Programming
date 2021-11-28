from itertools import chain, combinations
def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def check(a):
	s = set()

	for b in powerset(a):
		if sum(b) in s:
			return False
		s.add(sum(b))
	return True

def score(a, b):
	res = 0
	for i in range(len(a)):
		res += abs(a[i][0] - b[i])
	return res

'''#a = [47, 48, 25, 49, 42, 39, 11]
a = [22268348, 26154056, 92539317, 56433533, 11660532, 
     7769110, 59284602, 22980030, 74037939, 44594988, 13597331, 
     61356713, 78351129, 99213456, 29171244, 43897934, 55978004, 
     78896525, 59141338, 37513497]
a = list(map(int, '47 84 25 49 42 39 11'.split()))
s = {}

for b in powerset(a):
	b = sorted(b)
	if sum(b) not in s:
		s[sum(b)] = [b]
	else:
		s[sum(b)].append(b)

for i in s:
	if len(s[i]) == 1:
		continue
	#print(i, s[i])

while not check(a):
	a[1] += 1
print(a)'''

ans = [
        [9, 8, 7, 5],
        [41, 26, 46, 6, 45],
        [47, 48, 25, 49, 42, 41, 11],
        [394, 339, 48, 119, 351, 148, 259, 360, 180],
        [369, 884, 736, 519, 600, 692, 192, 681, 810, 414],
        [75, 8976, 9738, 7846, 894, 7154, 1309, 5226, 1946,
     9153, 6618, 9235],
        [730859, 822820, 367005, 729205, 32735, 922269,
     663615, 654166, 102877, 295581, 243608, 13593, 92262,
     731890, 979807],
        [9044391, 4589878, 8170436, 2509320, 1653070,
     2973252, 3454603, 6519286, 6616806, 6068732, 8084657,
     7598885, 1779172, 698825, 6604171, 8353477, 1080624,
     3501896],
        [1635285, 13869679, 13561040, 16039227, 10934788,
     3850897, 10195573, 10203186, 11236488, 15725470, 8054817,
     9347981, 3393142, 12071012, 12017809, 16844454, 7723099,
     15134722, 13663516],
        [22268349, 26154056, 92539317, 56433534, 11660532,
     7769110, 59284602, 22980030, 74037939, 44594988, 13597331,
     61356713, 78351129, 99213456, 29171244, 43897934, 55978004,
     78896525, 59141338, 37513497]
]

'''t = int(input())
n = int(input())
a = list(map(int, input().split()))'''
for _, a in enumerate(ans):
	n = len(a)
	a = [(a[i], i) for i in range(n)]
	a.sort()
	b = [0] * n
	curr = 1
	for i in range(n):
		b[a[i][1]] = curr
		curr <<= 1

	resMin = -1
	curr = 1
	res = 0
	while curr < a[-1][0]:
		c = [curr * i for i in b]
		x = score(a, c)
		print(_, x, c)
		if resMin == -1 or x < resMin:
			resMin = x
			res = curr
		curr <<= 1

	c = [res * i for i in b]
	#print('{' + str(c)[1:-1] + '},')
