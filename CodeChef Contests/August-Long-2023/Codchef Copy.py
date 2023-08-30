from itertools import permutations
c = 'codechef'
for _ in range(int(input())):
    s = input()
    for i in permutations(s):
        # print(*i, sep = '')
        for j in range(8):
            if s[j] == c[j]:
                break
        else:
            print(*i, sep = '')
            break
    else:
        print(-1)
