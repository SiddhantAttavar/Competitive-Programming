from random import randrange
l = [i for i in range(0, 10 + 1) if i % 2 == 0]
print(l[randrange(len(l))])