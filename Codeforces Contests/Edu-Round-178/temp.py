from sys import stderr
l = [int(i) for i in open('out.txt').readlines()]
l = sorted(l)

res = []
x = 0
d = 200
for i in l:
	if i <= x:
		continue
	res.append(i)
	x = i + d - 1
res = [res[0]] + [res[i] - res[i - 1] for i in range(1, len(res))]
print(len(res), file=stderr)
print(','.join(map(str, res)))
