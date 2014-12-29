import math

def nCr(n,r):
    if n == 0 and r == 0:
        return 1
    if n > 0 and r == 0:
        return 1
    if n == 0 and r > 0:
        return 0

    f = math.factorial
    result = 1;
    while(n > 0):
        b = 0
        a = n % 3
        n /= 3
        if(r > 0):
            b = r % 3
            r /= 3

        if a == 0 and b == 0:
            result *= 1
        elif a > 0 and b == 0:
            result *= 1
        elif a == 0 and b > 0:
            result *= 0
        else:
            print(str(a) + " " + str(b))
            result *= f(a) / f(b) / f(a-b)

    return (result % 3)

def main():
    t = int(input())
    while t > 0:
        n = int(input())
        comb_sum = 0
        for i in range(n + 1):
            comb_sum += nCr(n, i)

        t -= 1
        print(comb_sum % 1000000007)


if __name__ == '__main__':
    main()

