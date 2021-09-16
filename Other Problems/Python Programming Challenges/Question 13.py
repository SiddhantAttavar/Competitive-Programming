line = input()

letterCount = 0
digitCount = 0

for c in line:
    if c.isalpha():
        letterCount += 1
    elif c.isdigit():
        digitCount += 1

print(f'LETTERS {letterCount}')
print(f'DIGITS {digitCount}')