memo = {}

def solve(a, x, y, i):
    if (x, y, i) in memo:
        return memo[(x, y, i)]
    
    if i == len(a):
        return 0

    if x == -1:
        memo[(x, y, i)] = solve(a, i, y, i + 1) + 1
        return memo[(x, y, i)]
    if a[x] == a[i]:
        memo[(x, y, i)] = solve(a, i, y, i + 1)
        return memo[(x, y, i)]
    if y == -1:
        memo[(x, y, i)] = solve(a, x, i, i + 1) + 1
        return memo[(x, y, i)]
    if a[y] == a[i]:
        memo[(x, y, i)] = solve(a, x, i, i + 1)
        return memo[(x, y, i)]
    
    memo[(x, y, i)] = 1 + min(
        solve(a, i, y, i + 1),
        solve(a, x, i, i + 1),
    )
    return memo[(x, y, i)]

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    print(solve(a, -1, -1, 0))
    memo = {}