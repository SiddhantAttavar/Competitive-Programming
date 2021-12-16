from aocd import get_data, submit
data = get_data(day = 16, year = 2021).splitlines()
# data = '''EE00D40C823060'''.splitlines()
# data = '''38006F45291200'''.splitlines()
# data = '''04005AC33890'''.splitlines()
# data = '''880086C3E88112'''.splitlines()
# data = '''CE00C43D881120'''.splitlines()
# data = '''D8005AC2A8F0'''.splitlines()
# data = '''F600BC2D8F'''.splitlines()
# data = '''9C005AC2F8F0'''.splitlines()
# data = '''9C0141080250320F1802104A08'''.splitlines()

from collections import defaultdict
from functools import reduce

def evaluate(u):
	if len(graph[u][1]) == 0:
		return graph[u][0]
	
	res = [evaluate(v) for v in graph[u][1]]
	return funcDict[graph[u][0]](res)

funcDict = {
	0: sum,
	1: lambda a: reduce(lambda x, y: x * y, a),
	2: min,
	3: max,
	5: lambda a: int(a[0] > a[1]),
	6: lambda a: int(a[0] < a[1]),
	7: lambda a: int(a[0] == a[1])
}

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
	o = c
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
        
		packets.append([v, t, num, c - o])
	else:
		l = int(s[c], 2)
		c += 1
		if l == 0:
			num = int(s[c: c + 15], 2)
			c += 15
		else:
			num = int(s[c: c + 11], 2)
			c += 11
		
		packets.append([v, t, l, num, c - o])

for i in range(len(packets)):
	if packets[i][1] == 4 or packets[i][2] == 1:
		continue

	s = 0
	for j in range(i + 1, len(packets)):
		s += packets[j][-1]
		if s == packets[i][3]:
			packets[i][3] = j - i
			break

graph = defaultdict(lambda: [0, []])
curr = 0
stack = []
for p in packets:
	if len(stack) > 0:
		curr += 1
		graph[stack[-1][0]][1].append(curr)
	
	if len(p) == 5:
		stack.append([curr, p[3] + 1])
		graph[curr][0] = p[1]
	else:
		graph[curr][0] = p[2]
	
	stack[-1][1] -= 1

	if stack[-1][1] == 0:
		stack.pop()

res = evaluate(0)
print(res)
# submit(res, part = 'b', day = 16, year = 2021)
