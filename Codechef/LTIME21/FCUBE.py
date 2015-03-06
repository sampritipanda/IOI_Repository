# The First Cube

t = input()
M = 1000000007

# http://www.codechef.com/viewplaintext/2119430 - start

pm=[2, 325, 9375, 28178, 450775, 9780504, 1795265022]

def prime(N):
    d=N-1
    while d%2==0:
        d = d/2
        for i in range(7):
          a = pm[i]
          temp = d
          x = pow(a,temp,N)
          while (temp!=N-1 and x!=1 and x!=N-1):
            x = (x*x)%N
            temp = temp*2
          if (x!=N-1 and temp%2==0):
            return 0
    return 1

def prime1(n):
  i=2
  while(i*i<=n):
    if n%i==0:
      return 0
    i=i+1
  return 1

def prime2 ( n ):
  if n < 1795265022:
    return prime1(n)
  else :
    return prime(n)

# http://www.codechef.com/viewplaintext/2119430 - end

def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a % b)

def rho(n, c):
    t = 2
    h = 2
    d = 1

    while d == 1:
        t = (t * t + c) % n
        h = (h * h + c) % n
        h = (h * h + c) % n
        d = gcd(t - h, n)

    if d == n:
        return rho(c, c + 1)
    else:
        return d

while t > 0:
    n = input()
    answer = 1
    A_list = map(long, raw_input().split())
    factors = {}
    for A in A_list:
        answer = (answer * A) % M
        if prime2(A):
            if not A in factors: factors[A] = 1
            else: factors[A] += 1
        else:
            for i in range(2, 100000):
                while A % i == 0:
                    if not i in factors: factors[i] = 1
                    else: factors[i] += 1
                    A /= i
            while A > 1:
                if(prime2(A)):
                    if not A in factors: factors[A] = 1
                    else: factors[A] += 1
                    A = 1
                else:
                    curr_fact = rho(A, 1)
                    if not curr_fact in factors: factors[curr_fact] = 1
                    else: factors[curr_fact] += 1
                    A /= curr_fact

    for f in factors:
        if (factors[f] % 3) != 0:
            for l in range(3 - (factors[f] % 3)):
                answer = (answer * f) % M

    print answer

    t -= 1
