from aocd import get_data, submit
data = get_data(day = 16, year = 2021).splitlines()
# data = '''A0016C880162017C3686B18A3D4780'''.splitlines()
# data = '''8A004A801A8002F478'''.splitlines()
# data = '''38006F45291200'''.splitlines()d
# data = '''C200B40A82'''.splitlines()
# data = '''04005AC33890'''.splitlines()
# data = '''880086C3E88112'''.splitlines()
# data = '''CE00C43D881120'''.splitlines()
# data = '''D8005AC2A8F0'''.splitlines()
# data = '''F600BC2D8F'''.splitlines()
# data = '''9C005AC2F8F0'''.splitlines()
# data = '''9C0141080250320F1802104A08'''.splitlines()

from functools import reduce

funcDict = {
	0: sum,
	1: lambda a: reduce(lambda x, y: x * y, a),
	2: min,
	3: max,
	5: lambda a: int(a[0] > a[1]),
	6: lambda a: int(a[0] < a[1]),
	7: lambda a: int(a[0] == a[1])
}

def evaluate(u):
	if packets[u][1] == 4:
		return packets[u][2]

	res = []
	for v in graph[u]:
		res.append(evaluate(v))
	return funcDict[packets[u][1]](res)

s = bin(int(data[0], 16))[2:]
for i in data[0]:
	if i != '0':
		break
	s = '0' * 4 + s
n = len(s)
if n % 4 != 0:
	s = '0' * (4 - n % 4) + s
n = len(s)
c = 0
packets = []

while c < n and '1' in s[c:]:
	v = int(s[c: c + 3], 2)
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

		packets.append([v, t, num, c])
	else:
		l = int(s[c], 2)
		c += 1
		if l == 0:
			num = int(s[c: c + 15], 2)
			c += 15
		else:
			num = int(s[c: c + 11], 2)
			c += 11
		
		packets.append([v, t, l, num, c])

stack = []
graph = [[] for _ in range(len(packets))]

for i, u in enumerate(packets):
	if len(stack) > 0:
		p = stack[-1]
		graph[p].append(i)
		packets[p][3] -= 1
		if packets[p][3] == 0:
			stack.pop()
	
	while len(stack) > 0:
		p = stack[-1]
		if packets[p][2] == 0 and packets[p][3] <= u[-1] - packets[p][-1]:
			stack.pop()
		else:
			break

	if u[1] != 4:
		stack.append(i)

print(evaluate(0))
# submit(res, part = 'b', day = 16, year = 2021)
