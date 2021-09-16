for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    curr = 1
    res = 1
    minDiff = 0
    for i in range(1, n):
        if minDiff >= a[i] and a[i] - a[i - 1] >= a[i]:
            curr += 1
            minDiff = a[i] - a[i - 1]
            res = max(res, curr)
        else:
            curr = 1
            minDiff = 0
    print(res)