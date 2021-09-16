from math import gcd
n, a, b = map(int, input().split())
a, b = sorted((a, b))
count = 0
lcm = a * b // gcd(a, b)
for i in range(lcm):
    x = 0
    if i % a == 0:
        x += i // a
    if i % b == 0:
        x += i // b
    if x % 2 == 0:
        count += 1
res = count * (n // lcm)
for i in range(n % lcm):
    x = 0
    if i % a == 0:
        x += i // a
    if i % b == 0:
        x += i // b
    if x % 2 == 0 and (i % a == 0 or i % b == 0):
        print(i + a)
        res += 1
print(n - res)