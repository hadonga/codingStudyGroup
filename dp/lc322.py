#给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，
# 每种硬币的数量无限，再给一个总金额 amount，
# 问你最少需要几枚硬币凑出这个金额， 如果不可能凑出，算法返回 -1 。

# 因为需要得到最优解，此问题为动态规划。

# 暴力破解
# 1. 确定状态为 amount 
# 2. 确定选择为 硬币
# 3. 最小值
coins = [1,3,5,10]
amount = 32

def dp(coins, amount):
    if amount == 0:
        return 0
    if amount < 0:
        return -1
    
    res = 10000
    for coin in coins:
        subProblem = dp(coins, amount - coin)
        if subProblem == -1:
            continue
        res = min(res, subProblem +1)
    return res

resNormal = dp(coins, amount)
print(resNormal)

memo = [-99]* (amount+1) 
def dpMemo(coins, amount):
    if amount == 0:
        return 0
    if amount < 0:
        return -1
    if memo[amount] != -99:
        return memo[amount]

    res = 10000
    for coin in coins:
        subProblem = dpMemo(coins, amount - coin)
        if subProblem == -1:
            continue
        res = min(res, subProblem +1)
    memo[amount] = res
    return memo[amount]

resMemo = dpMemo(coins, amount)
print(resMemo)

def coinChange(coins, amount):
    dp = [amount+1] * (amount+1)

    # base case 
    dp[0] = 0
    # outter for 遍历所有状态
    for i in range(0, len(dp)):
        for coin in coins:
            if i - coin<0 :
                continue
            dp[i] = min(dp[i], 1 + dp[i - coin] )

    if dp[amount] == amount +1:
        res = -1
    res = dp[amount] 
    return  res

resTable = coinChange(coins, amount)
print(resTable)