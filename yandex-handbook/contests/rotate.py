class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n // 2):
            for j in range(i, n-1-i):
                tmp1 = matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = matrix[i][j]
                tmp2 = matrix[n - 1 - i][n - 1 - j]
                matrix[n - 1 - i][n - 1 - j] = tmp1
                tmp1 = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = tmp2
                matrix[i][j] = tmp1


if __name__ == '__main__':
    matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Solution().rotate(matrix)
    print(matrix)
