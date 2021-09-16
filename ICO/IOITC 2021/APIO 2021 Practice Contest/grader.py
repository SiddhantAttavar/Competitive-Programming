k = 293 * 311
file = open(r'defence\outputs\04.out', 'r')
x = file.readlines()
if len(x) != k:
    print('Failed')
else:
    for line in x:
        x1, x2, y1, y2 = map(int, line.split())
        if x1 > x2 or y1 > y2 or (x2 - x1) * (y2 - y1) != 9973 * 99991:
            print('Failed')
            break
    else:
        print('Passed')
file.close()