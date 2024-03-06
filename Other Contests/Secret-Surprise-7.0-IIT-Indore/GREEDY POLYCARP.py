n, m = map(int, input().split())
v = [list(map(int, input().split())) for _ in range(n)]
print(max([max(i) for i in v]))
