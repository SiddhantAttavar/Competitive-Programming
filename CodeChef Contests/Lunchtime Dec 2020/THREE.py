from collections import defaultdict
for _ in range(int(input())):
    s = input()
    map = defaultdict(lambda: 0)
    for c in s:
        map[c] += 1
    a = b = 0
    for i in map:
        a += map[i] // 2
        b += map[i] % 2
    print(a, b)
    res = min(a, b)
    a -= min(a, b)
    print(res + (a * 2) // 3)