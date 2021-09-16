line = input()

upperCount = 0
lowerCount = 0

for c in line:
    if c.isupper():
        upperCount += 1
    elif c.islower():
        lowerCount += 1

print(f'UPPER {upperCount}')
print(f'LOWER {lowerCount}')