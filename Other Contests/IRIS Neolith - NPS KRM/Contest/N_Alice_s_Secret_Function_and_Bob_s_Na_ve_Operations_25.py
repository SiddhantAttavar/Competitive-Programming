n = int(input())
a = list(range(n))
curr = 1
moves = []
while len(a) > 2:
    a = a[::2]
    for i in a:
        if i + curr < n:
            moves.append((i, i + curr))
    curr *= 2
print(len(moves))
for x, y in moves:
    print(x + 1, y + 1)