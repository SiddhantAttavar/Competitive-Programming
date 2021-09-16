from random import randrange
l = [i for i in range(0, 10 + 1) if i % 35 == 0]
print(l[randrange(len(l))])