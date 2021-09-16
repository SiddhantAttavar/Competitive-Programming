l = []
while True:
    try:
        name, age, height = input().split(',')
        age, height = int(age), int(height)
        l.append((name, age, height))
    except:
        break

l.sort(key = lambda x: x[2])
l.sort(key = lambda x: x[1])
l.sort(key = lambda x: x[0])


print(l)