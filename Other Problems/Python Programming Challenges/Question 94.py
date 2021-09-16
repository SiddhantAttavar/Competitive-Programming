done = set()
res = []
for i in [12,24,35,24,88,120,155,88,120,155]:
    if i not in done:
        res.append(i)
        done.add(i)
print(res)