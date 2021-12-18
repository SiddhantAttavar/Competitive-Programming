from math import sqrt

# x is robot initial positions
# s is robot speed
x = [1, 2, 6, 7, 10, 14, 20]
s = [2, 3, 2, 1, 1, 3, 3]

# n = no of robots
# l = corridor length
# res = max time
n = len(x)
l = 20
res = 0

# Iterate through all subsets of i
for i in range(1 << n):
	v = s.copy()
	p = x.copy()
	for j in range(n):
		if i & (1 << j):
			v[j] *= -1
	
	flag = True
	finTime = 0
	while flag:
	# for _ in range(5):
		t = [1e9] * (n - 1)
		for i in range(n - 1):
			d = p[i + 1] - p[i]
			if ((v[i] > 0 and v[i + 1] < 0) or 
				(v[i] > 0 and v[i + 1] > 0 and v[i] > v[i + 1]) or
				(v[i] < 0 and v[i + 1] < 0 and v[i] < v[i + 1])):
				t[i] = d / abs(v[i] - v[i + 1])
		
		minT = 0
		for i in range(1, n - 1):
			if t[i] < t[minT]:
				minT = i
		
		for i in range(n):
			p[i] += t[minT] * v[i]
		
		v1 = v[minT]
		v2 = v[minT + 1]
		assert (v1 + v2) ** 2 - 4 * v1 * v2 >= 0
		v2f1 = ((v1 + v2) + sqrt((v1 + v2) ** 2 - 4 * v1 * v2)) / 2
		v2f2 = ((v1 + v2) - sqrt((v1 + v2) ** 2 - 4 * v1 * v2)) / 2
		if abs(v2 - v2f1) <= 1e-6:
			v[minT + 1] = v2f2
		else:
			v[minT + 1] = v2f1
		v[minT] = v[minT + 1] - v1 - v2

		finTime += t[minT]

		for i in range(n):
			if 0 <= p[i] <= 20:
				break
		else:
			flag = False
	
	res = max(res, finTime)

print(int(res))
