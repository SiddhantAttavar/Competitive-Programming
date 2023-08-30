c = 'codechef'
x = 0
while True:
	try:
		s = input()
		if s == '-1':
			continue

		if len(s) != 8:
			print(s)
			print(c)
			exit()

		for i in range(8):
			if s[i] == c[i]:
				print(s)
				print(c)
				exit()

		x += 1
		if x % 1000 == 0:
			print(x / 1000, '%')
	except EOFError:
		break
