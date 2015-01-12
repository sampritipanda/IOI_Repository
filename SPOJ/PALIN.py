import math

def is_palindrome(n):
    num = n
    rev = 0

    while(num > 0):
        dig = num % 10
        rev = rev * 10 + dig
        num /= 10

    return n == rev

def main():
    t = int(input())
    while t > 0:
        n = int(input())
        while True:
            n += 1
            if is_palindrome(n):
                print(n)
                break
        t -= 1


if __name__ == '__main__':
    main()
