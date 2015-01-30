# Chhota Bheem and Kirmada

T = input()

while T > 0:
    N, K = raw_input().split()
    N, K = long(N), long(K)

    power = 0
    while K > 0:
        power += 1
        K -= 9 * pow(10, power - 1) * power

    K += 9 * pow(10, power - 1) * power

    if K % power == 0:
        num = pow(10, power - 1) + K/power - 1
        print num % 10
    else:
        num = pow(10, power - 1) + K/power
        num2 = num/pow(10, power - (K % power))
        print num2 % 10

    T -= 1

