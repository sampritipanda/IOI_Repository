def iden_mat(x):
    c = [[0 for j in range(x)] for i in range(x)]
    for i in range(x):
        c[i][i] = 1
    return c

def matmul(x, y, mod):
    m = len(x)
    n = len(y[0])
    p = len(x[0])

    c = [[0 for j in range(n)] for i in range(m)]

    for i in range(m):
        for j in range(n):
            for k in range(p):
                c[i][j] += x[i][k] * y[k][j]
                c[i][j] %= mod

    return c

def matpow(x, n, m):
    if n == 0:
        return iden_mat(len(x[0]))
    if n % 2 == 1:
        return matmul(x, matpow(x, n - 1, m), m)
    y = matpow(x, n/2, m)
    return matmul(y, y, m)

n = input()
k = input()
m = input()

a = [[0, 1]]
b = [[0, k - 1], [1, k - 1]]

ans = matmul(a, matpow(b, n, m), m)
print ans[0][1]
