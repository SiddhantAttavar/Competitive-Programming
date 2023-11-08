x, p, q = map(int, input().split())
n  = int(input())
res = (0, (-1, -1))
v = [list(map(int, input().split())) for _ in range(n)]
m = int(input())

for i in range(m):
	o, a, b = map(int, input().split())
	if o == 1:
		if x >= a and (p + b) >= res[0]:
			res = (p + b, (i + 1, -1))
	else:
		for j in range(n):
			if 2 * min(x, v[j][0]) >= a and (q + b + v[j][1]) >= res[0]:
				res = (q + b + v[j][1], (i + 1, j + 1))

if res[1][0] == -1:
	print("Forget about apartments. Live in the dormitory.")
elif res[1][1] == -1:
	print(f"You should rent the apartment #{res[1][0]} alone.\n");
else:
	print(f"You should rent the apartment #{res[1][0]} with the friend #{res[1][1]}.\n");
