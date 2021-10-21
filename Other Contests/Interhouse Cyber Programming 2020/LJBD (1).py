n = int(input())
w = list(map(int, input().split()))
w.sort()
w.reverse()

c = 0
cMax = w[0]
for i in w:
    if i < cMax - 4:
        cMax = i
        c += 1

print(c + 1)