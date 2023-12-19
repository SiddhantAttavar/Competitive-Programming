from aocd import get_data, submit
data = get_data(day = 19, year = 2023).splitlines()
# data = '''px{a<2006:qkq,m>2090:A,rfg}
# pv{a>1716:R,A}
# lnx{m>1548:A,A}
# rfg{s<537:gd,x>2440:R,A}
# qs{s>3448:A,lnx}
# qkq{x<1416:A,crn}
# crn{x>2662:A,R}
# in{s<1351:px,qqz}
# qqz{s>2770:qs,m<1801:hdj,R}
# gd{a>3333:R,R}
# hdj{m>838:A,pv}
#
# {x=787,m=2655,a=1222,s=2876}
# {x=1679,m=44,a=2067,s=496}
# {x=2036,m=264,a=79,s=2244}
# {x=2461,m=1339,a=466,s=291}
# {x=2127,m=1623,a=2188,s=1013}'''.splitlines()

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

def solve(s):
	l = {c: 1 for c in 'xmas'}
	r = {c: 4000 for c in 'xmas'}
	for i in s:
		if '<=' in i:
			r[i[0]] = min(r[i[0]], int(i[3:]))
		elif '>=' in i:
			l[i[0]] = max(l[i[0]], int(i[3:]))
		elif '>' in i:
			l[i[0]] = max(l[i[0]], int(i[2:]) + 1)
		elif '<' in i:
			r[i[0]] = min(r[i[0]], int(i[2:]) - 1)
	res = 1
	for c in 'xmas':
		# print(r[c], l[c])
		res *= max(0, r[c] - l[c] + 1)
	# print(l, r, res)
	return res

def dfs(u, s):
	# print(u, s)
	if u == 'A':
		return solve(s)
	elif u == 'R':
		return 0

	res = 0
	for i in w[u][:-1]:
		if '<' in i[0]:
			a, b = i[0].split('<')
			res += dfs(i[1], s + [i[0]])
			s.append(f'{a}>={b}')
		else:
			a, b = i[0].split('>')
			res += dfs(i[1], s + [i[0]])
			s.append(f'{a}<={b}')
	return res + dfs(w[u][-1][0], s)

res = dfs('in', [])

print(res)
submit(res, part = 'b', day = 19, year = 2023)
