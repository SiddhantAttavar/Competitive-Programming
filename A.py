in_file = open("abbreviation.in", 'r')
out_file = open("abbreviation.out", 'w')
input = lambda: in_file.readline()
print = lambda x: out_file.write(x)

def comb(l):
    if not l:
        return ''
    if len(l) == 1:
        return l[0]
    s = ''
    for w in l:
        s += w[0]
    res = s + ' ('
    for w in l:
        res += w
    x = l[-1][-1]
    res = res[:-1] + ')' + x
    return res


for l in in_file.readlines():
    l += '\n'
    d = []
    s = ''
    for c in l:
        s += c
        if not c.isalpha():
            d.append(s)
            s = ''

    c = []
    res = ''
    for s in d:
        if len(s) == 1 or not s[0].isupper():
            res += comb(c)
            c = []
            res += s
            continue

        x = 0
        for i in s:
            x += i.isupper()

        if x > 1 or len(s) == 2:
            res += comb(c)
            c = []
            res += s
            continue

        c.append(s)
        if s[-1] == ' ':
            continue

        res += comb(c)
        c = []
    
    res += comb(c)
    res = res[:-1]
    print(''.join(res))
