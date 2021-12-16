from aocd import get_data, submit
data = get_data(day = 16, year = 2021).splitlines()
# data = '''A0016C880162017C3686B18A3D4780'''.splitlines()
# data = '''8A004A801A8002F478'''.splitlines()
# data = '''38006F45291200'''.splitlines()

s = bin(int(data[0], 16))[2:]
n = len(s)
if n % 4 != 0:
	s = '0' * (4 - n % 4) + s
n = len(s)
res = 0
c = 0

while c < n and '1' in s[c:]:
	v = int(s[c: c + 3], 2)
	res += v
	c += 3
	t = int(s[c: c + 3], 2)
	c += 3
	
	if t == 4:
		num = ''
		while s[c] == '1':
			num += s[c + 1: c + 5]
			c += 5
		num += s[c + 1: c + 5]
		c += 5
		num = int(num, 2)
	else:
		l = int(s[c], 2)
		c += 1
		if l == 0:
			num = int(s[c: c + 15], 2)
			c += 15
		else:
			num = int(s[c: c + 11], 2)
			c += 11

print(res)
# submit(res, part = 'a', day = 16, year = 2021)
