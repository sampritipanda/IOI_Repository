#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

int N, B, K, X;

int modpow(int base, int exp, int mod) {
  int result = 1;

  while(exp) {
    if(exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }

  return result;
}

vector<long long> merge(vector<long long> A, vector<long long> B, long long factor) {
  vector<long long> res(X);

  for(int i = 0; i < X; i++) {
    for(int j = 0; j < X; j++) {
      res[((i * factor) + j) % X] += A[i] * B[j];
      res[((i * factor) + j) % X] %= MOD;
    }
  }

  return res;
}

vector<long long> matpow(vector<long long> A, int exp) {
  if(exp == 0) {
    vector<long long> ans(X);
    ans[0] = 1;
    return ans;
  }

  if(exp & 1) return merge(matpow(A, exp - 1), A, modpow(10, 1, X));

  vector<long long> temp = matpow(A, exp/2);
  return merge(temp, temp, modpow(10, exp/2, X));
}

int main() {
  cin >> N >> B >> K >> X;

  vector<long long> A(X);
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    A[x % X]++;
  }

  vector<long long> ans = matpow(A, B);
  cout << ans[K] << endl;
}
