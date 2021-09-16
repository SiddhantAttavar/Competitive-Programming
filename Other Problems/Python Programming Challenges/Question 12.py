res = []

i = '2'
for j in '02468':
    for k in '02468':
        for l in '02468':
            res.append(i + j + k + l)

print(*res, sep = ',')