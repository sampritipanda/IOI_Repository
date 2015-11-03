#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return (a * b)/gcd(a, b);
}

int main() {
  long long t, w, b; cin >> t >> w >> b;

  long long a = t/lcm(w, b) * min(w, b);
  a += min(min(w, b) - 1, t);

  cout << a/gcd(a, t) << "/" << t/gcd(a, t) << endl;
}
