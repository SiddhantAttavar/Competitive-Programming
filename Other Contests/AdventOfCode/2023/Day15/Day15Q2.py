from aocd import get_data, submit
data = get_data(day = 15, year = 2023).splitlines()
# data = '''rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7'''.splitlines()

def hash(s):
	res = 0
	for c in s:
		res = (17 * (res + ord(c))) % 256
	return res

res = 0
lens = [{} for _ in range(256)]
l = [None] * 256

for r in data[0].split(','):
	if r[-1] == '-':
		s = r[:-1]
		c = hash(s)
		# print(s, '-')
		if s not in lens[c]:
			continue

		lens[c].pop(s)
	else:
		s = r.split('=')[0]
		x = int(r.split('=')[1])
		# print(s, x)
		c = hash(s)
		lens[c][s] = x

# print(lens)
# print(l)
for i, r in enumerate(lens):
	# print(v, end = ' ')
	for j, x in enumerate(r.values()):
		res += x * (j + 1) * (i + 1)
	
print(res)
submit(res, part = 'b', day = 15, year = 2023)
