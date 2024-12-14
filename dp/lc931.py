#「下降路径最小和」，
# 输入为一个 n * n 的二维数组 matrix，
# 请你计算从第一行落到最后一行，经过的路径和最小为多少？


class Solution():
    def __init__(self):
        self.memo =[]

    def minFallingPathSum(self, matrix):
        n = len(matrix)
        res = 10e8
        self.memo = [[66666]*n]*n

        for j in range(n):
            res = min(res, self.dp(matrix, n-1, j))
        
        return res

    def dp(self, matrix, i, j):
        # index check
        if i < 0 or j < 0 or i >=len(matrix) or j>len(matrix[0]):
            return 99999
        
        if i == 0:
            return matrix[0][j]
        
        if self.memo[i][j]!=66666:
            return self.memo[i][j]

        self.memo[i][j] = matrix[i][j] + min(
                                self.dp(matrix, i-1, j),
                                self.dp(matrix, i-1, j-1),
                                self.dp(matrix, i-1, j+1))
        return self.memo[i][j]

matrix = [[2,1,3],[6,5,4],[7,8,9]]

function = Solution()

print(function.minFallingPathSum(matrix))