# NPS INR
# Round 1 - Question 1
def thousands_seperator(number):return f'{number:,}'
print(thousands_seperator(int(input('Enter integer: '))))

# Round 1 - Question 2
f,s={},input('Enter string: ').split()
for c in s:f[c]=f.get(c,0)+1
print(*(f[c] for c in s),sep=' ')