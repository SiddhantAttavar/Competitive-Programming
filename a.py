for t in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Initialize DP table
    dp = [[0, 0] for _ in range(N)]
    
    # We also maintain the max pair sum up to each index
    max_pair_sum = [0] * N
    
    # Base case: no "small" indices possible for the first two elements
    for i in range(2, N):
        max_pair_sum[i] = max(A[i-1] + A[i-2], B[i-1] + B[i-2])
    
    # DP computation
    for i in range(2, N):
        # Check if current A[i] or B[i] satisfy the "small index" condition
        if A[i] <= max_pair_sum[i-1]:
            dp[i][0] = dp[i-1][0] + 1
        else:
            dp[i][0] = dp[i-1][1]
            
        if B[i] <= max_pair_sum[i-1]:
            dp[i][1] = dp[i-1][0] + 1
        else:
            dp[i][1] = dp[i-1][1]

    # Final result for the current test case
    print(max(dp[N - 1][0], dp[N - 1][1]))
