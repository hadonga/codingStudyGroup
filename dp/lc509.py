def fib(N:int):
    if N==1 or N==2:
        return 1
    return fib(N-1)+ fib(N-2)

def fibFast(N:int):
    memo = [0]*(N+1)
    return dp(memo, N)

def dp(memo, n):
    if n == 0 or n == 1:
        return n
    if memo[n] != 0:
        return memo[n]
    memo [n] = dp(memo, n -1) + dp (memo, n-2)
    print(memo)
    return memo[n]

N = 15
resultFast = fibFast(N)
result = fib(N)
print(result, resultFast)

# 我们可以看出这是一个从下到上的计算，
# 把memo直接拿出来成为 DP table

def fibOpt(N):
    if N == 0:
        return 0
    dp = [0]* (N+1)
#base case
    dp[0] = 0 
    dp[1] = 1
#状态转移, 问题从之前答案中求解
    for i in range(2, N):
        dp[i] = dp[i-1]+ dp[i-2]

    return dp[N]

resultOpt = fibOpt(N)
print(result)


