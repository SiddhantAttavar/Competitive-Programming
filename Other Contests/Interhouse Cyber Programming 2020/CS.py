n = int(input())
a = [int(input()) for _ in range(n)]
dp = [1] * n
flag=True
for i in a:
    if 0<=i<=10**7:
        continue
    flag=False
if 1<=n<=100000 and flag==True:
    for i in range(n):
        for j in range(i):
            if a[i] > a[j]:
                dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))