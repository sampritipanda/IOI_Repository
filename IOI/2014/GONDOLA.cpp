#include <cstdio>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

#define MOD 1000000009

int N;
int A[100000];
int C[250001];
map<int, int> freq;

bool valid() {
  freq.clear();
  for(int i = 0; i < N; i++) {
    freq[A[i]]++;
  }
  for(auto it: freq) {
    if(it.second > 1) return false;
  }

  int min_point = freq.begin()->first;
  if(min_point > N) return true;

  int i;
  for(i = 0; i < N; i++) {
    if(A[i] == min_point) break;
  }

  for(int j = 0; j < min_point - 1; j++) {
    i = (i - 1 + N) % N;
  }

  for(int j = 1; j <= N; j++) {
    if(A[i] <= N && A[i] != j) return false;
    i = (i + 1) % N;
  }

  return true;
}

long long modpow(long long base, long long exp) {
  long long result = 1;
  while(exp) {
    if(exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

int main() {
  int T; scanf("%d", &T);

  scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  if(T <= 3) {
    printf("%d\n", valid() ? 1 : 0);
  }
  else if(T <= 6){
    int max_val = N;
    int min_val = INT_MAX/2;
    int min_val_pos = 0;
    for(int i = 0; i < N; i++) {
      max_val = max(max_val, A[i]);
      if(A[i] < min_val) {
        min_val = A[i];
        min_val_pos = i;
      }
    }
    if(min_val > N) {
      min_val = 1;
      min_val_pos = 0;
    }

    int i = min_val_pos;
    for(int j = 0; j < min_val - 1; j++) {
      i = (i - 1 + N) % N;
    }

    int prev = -1;
    for(int j = 1; j <= N; j++) {
      if(A[i] == max_val) {
        prev = j;
      }
      else {
        C[A[i]] = j;
      }
      i = (i + 1) % N;
    }

    for(int j = N + 1; j <= max_val; j++) {
      if(C[j] != 0) continue;
      C[j] = prev;
      prev = j;
    }

    printf("%d", max_val - N);
    for(int j = N + 1; j <= max_val; j++) printf(" %d", C[j]);
    printf("\n");
  }
  else {
    if(!valid()) printf("0\n");
    else {
      vector<int> vec;
      vec.push_back(N);
      bool fixed = false;
      for(int i = 0; i < N; i++) {
        if(A[i] <= N) {
          fixed = true;
        }
        else {
          vec.push_back(A[i]);
        }
      }
      sort(vec.begin(), vec.end());

      long long ans = 1;
      int j = 1;
      for(int i = vec.size() - 1; i >= 1; i--, j++) {
        ans = (ans * modpow(j, vec[i] - vec[i - 1] - 1)) % MOD;
      }
      if(!fixed) ans = (ans * N) % MOD;

      printf("%lld\n", ans);
    }
  }
}
