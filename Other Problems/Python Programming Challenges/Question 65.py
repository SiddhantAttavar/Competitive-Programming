def solve(n):
    return 0 if n == 0 else 100 + solve(n - 1)

print(solve(5))