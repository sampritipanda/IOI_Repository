from sys import setrecursionlimit
setrecursionlimit(10**7)

def median(a, b, c):
    if a > b: a, b = b, a
    if a > c: a, c = c, a
    if b > c: b, c = c, b
    return b

def f1(n): return (-n*n*n + 947*n*n + 20647474747*n + 47) // 20000000047

def f2(n): return (-n*n + 2084747*n + 47) // 2494747

def f3(n): return (-n*n*n + 19647*n*n + 23254474747*n - 25384747*(n%97)*n + 47 ) // 25382294747

def sort_helper(A, lo, hi):
    n = hi - lo
    if n <= 2:
        if n == 2 and A[lo] > A[lo+1]: A[lo], A[lo+1] = A[lo+1], A[lo]
        return
    a = median( 0, n-1, f1(n) )
    b = median( 0, n-1, f2(n) )
    c = median( 0, n-1, f3(n) )
    sort_helper( A, lo, lo+a )
    sort_helper( A, hi-b, hi )
    sort_helper( A, lo, lo+c )

# this is the main function
def k1_sort(A):
    sort_helper( A, 0, len(A) )
