from aocd import get_data, submit
data = get_data(day = 15, year = 2023).splitlines()
# data = '''rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7'''.splitlines()

def hash(s):
	res = 0
	for c in s:
		res = (17 * (res + ord(c))) % 256
	return res

res = 0

for r in data[0].split(','):
	res += hash(r)

print(res)
submit(res, part = 'a', day = 15, year = 2023)
