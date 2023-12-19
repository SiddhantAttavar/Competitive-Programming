from aocd import get_data, submit
data = get_data(day = 19, year = 2023).splitlines()
data = '''px{a<2006:qkq,m>2090:A,rfg}
pv{a>1716:R,A}
lnx{m>1548:A,A}
rfg{s<537:gd,x>2440:R,A}
qs{s>3448:A,lnx}
qkq{x<1416:A,crn}
crn{x>2662:A,R}
in{s<1351:px,qqz}
qqz{s>2770:qs,m<1801:hdj,R}
gd{a>3333:R,R}
hdj{m>838:A,pv}

{x=787,m=2655,a=1222,s=2876}
{x=1679,m=44,a=2067,s=496}
{x=2036,m=264,a=79,s=2244}
{x=2461,m=1339,a=466,s=291}
{x=2127,m=1623,a=2188,s=1013}'''.splitlines()

res = 0

flag = False
w = {}
l = []
for r in data:
	if not r:
		flag = True
		continue
	
	if not flag:
		x, y = r.split('{')
		w[x] = []
		for i in y[:-1].split(','):
			w[x].append(i.split(':'))
	else:
		l.append(r[1:-1].split(','))

# print(w)

def dfs(u):
	# print(u)
	if u == 'A':
		return True
	elif u == 'R':
		return False

	for i in w[u][:-1]:
		# print(i)
		if eval(i[0]):
			return dfs(i[1])
	return dfs(w[u][-1][0])

x = m = a = s = 0
for i in l:
	exec('\n'.join(i))
	if dfs('in'):
		res += x + m + a + s

print(res)
# submit(res, part = 'a', day = 19, year = 2023)
