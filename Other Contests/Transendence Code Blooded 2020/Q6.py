inFile = open('D:\Downloads\E_F_G_H\F\data\secret\\' + input() + '.in', 'r')
finput = inFile.readline
MOD = 10 ** 9 + 7
def power(x, y):
    res = 1
    while y > 0:
        if  y % 2 == 1:
            res = mul(res, x)
        x = mul(x, x)
        y //= 2
    return res   
mul = lambda x, y: (x * y) % MOD
div = lambda x, y: mul(x, power(y, MOD - 2))

fact = [1]
for i in range(1, 200001):
    fact.append(mul(fact[i - 1], i))

for i in range(1, int(finput().strip()) + 1):
    print('Case #' + str(i), end = ': ')
    m, n = map(int, finput().split())
    print(div(fact[m + n], mul(fact[m], fact[n])))
