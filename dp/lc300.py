# 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
# Case1: 
# 输入：nums = [10,9,2,5,3,7,101,18]; 输出：4
# 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
# Case2:
# 输入：nums = [7,7,7,7,7,7,7]; 输出：1

#我们的定义是这样的：dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。

def lengthofLIS(nums):
    dp = [1] * len(nums)
    for i in range(0, len(nums)):
        for j in range(0, i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    res = 0
    for i in range(0, len(dp)):
        res = max(res, dp[i])
    return res


nums = [10,9,2,5,3,7,101,18,200]
print(lengthofLIS(nums))

# 1、明确 dp 数组的定义。这一步对于任何动态规划问题都很重要，如果不得当或者不够清晰，会阻碍之后的步骤。
# 2、根据 dp 数组的定义，运用数学归纳法的思想，假设 dp[0...i-1] 都已知，
# 想办法求出 dp[i]，一旦这一步完成，整个题目基本就解决了。