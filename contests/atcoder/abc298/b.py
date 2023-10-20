n = int(input())

vector_a = []
vector_b = []

def rotate_vector(vector):
    new_vector = []

    for i in range(1, n + 1):
        row = []
        for j in range(1, n + 1):
            row.append(vector[n - j][i - 1])
        new_vector.append(row)

    return new_vector

def are_equal(vector_a, vector_b):
    for i in range(n):
        for j in range(n):
            if vector_a[i][j] == 1 and vector_b[i][j] == 0:
                return False
    return True

for i in range(n):
    vector_a.append(list(map(int, input().split())))

for i in range(n):
    vector_b.append(list(map(int, input().split())))

for i in range(4):
    if are_equal(vector_a, vector_b):
        print("Yes")
        break

    vector_a = rotate_vector(vector_a)
else:
    print("No")
