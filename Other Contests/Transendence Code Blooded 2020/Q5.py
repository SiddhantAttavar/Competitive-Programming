def dfs(i, j):
    if i == -1 or i == m or j == -1 or j == n:
        return 0
    if dp[i][j] == 0 or visited[i][j]:
        return 0
    visited[i][j] = True
    return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1)
for i in range(1, int(input()) + 1):
    print('Case #' + str(i), end = ': ')
    m, n = map(int, input().split())
    dp = [list(map(int, input().split())) for i in range(m)]
    visited = [[False] * n for i in range(m)]
    res = 0
    for i in range(m):
        for j in range(n):
            if not visited[i][j]:
                res = max(res, dfs(i, j))
    print(res)
