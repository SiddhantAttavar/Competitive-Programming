from aocd import get_data, submit
data = get_data(day = 13, year = 2021).splitlines()

p = []
f = True
for l in data:
	if not l:
		f = False
	elif f:
		p.append(tuple(map(int, l.split(','))))
	else:
		n = []
		a, b = l.split('=')
		b = int(b)
		for x, y in p:
			if a[-1] == 'x' and x > b:
				n.append((b - (x - b), y))
			elif a[-1] == 'y' and y > b:
				n.append((x, b - (y - b)))
			else:
				n.append((x, y))
		p = list(set(n))
		break

print(len(p))
# submit(len(p), part = 'a', day = 13, year = 2021)
