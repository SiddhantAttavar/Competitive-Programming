n, l, u = map(int, input().split())
w = [(int(r), i) for i, r in enumerate(input().split())]

w.sort(key = lambda x: x[0])
prefSum = [0]
for i in range(n):
    prefSum.append(prefSum[i] + w[i][0])

done = False
for s in range(1, n):
    if not ((prefSum[s] < l and (prefSum[n] - prefSum[n - s]) < l) or
        (prefSum[s] > u and (prefSum[n] - prefSum[n - s]) > u)):
        for i in range(n - s):
            sum = prefSum[i + s] - prefSum[i]
            if sum >= l and sum <= u:
                print(s)
                for j in range(i, i + s):
                    print(w[j][1], end = ' ')
                break
        done = True
        break

if not done:
    print(0)