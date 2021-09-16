from math import sqrt

x = y = 0
while True:
    try:
        dir, steps = input().split()
        steps = int(steps)
        nextStep = {
            'UP': (x, y - steps),
            'DOWN': (x, y + steps),
            'LEFT': (x - steps, y),
            'RIGHT': (x + steps, y)
        }

        x, y = nextStep[dir.upper()]
    except:
        break

print(sqrt(x * x + y * y))