import sys

def main():
    adjacency_matrix = []

    line = list(map(int, input().split()))
    adjacency_matrix.append(line)
    n = len(line)
    for i in range(n-1) :
        line = list(map(int, input().split()))
        adjacency_matrix.append(line)
    count = 0
    for i in range(n):
        if adjacency_matrix[i][i] == 1:
            count += 1
            print(i)
    if count == 0:
        print("NO LOOPS")
if __name__ == '__main__':
    main()