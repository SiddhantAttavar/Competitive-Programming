from random import randint
N = 10 ** 5
a = ord('a')
z = ord('z')
c = 'codechef'

print(N)
for _ in range(N):
	s = list(c)
	for i in range(8):
		if randint(0, 1):
			s[i] = chr(randint(a, z))
	print(*s, sep = '')
