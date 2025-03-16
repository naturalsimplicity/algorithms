

def main():
    n = int(input())
    m = int(input())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    i = int(input())
    j = int(input())

    res = []
    if i > 0:
        res.append(matrix[i-1][j])
    if i < n-1:
        res.append(matrix[i+1][j])
    if j > 0:
        res.append(matrix[i][j-1])
    if j < m-1:
        res.append(matrix[i][j+1])
    res.sort()
    print(' '.join(map(str, res)))


if __name__ == '__main__':
    main()
