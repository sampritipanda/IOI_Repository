#include <cstdio>
#include <algorithm>

using namespace std;

int L[1000001], C[1000001];
int A[1000001];
int C2_map[1000001];

inline int scan() {
  int N = 0;
  char c = getchar_unlocked();
  while(c < '0' || c > '9') {
      c = getchar_unlocked();
    }

  while(c >= '0' && c <= '9') {
      N = (N<<1) + (N<<3) + c - '0';
      c = getchar_unlocked();
    }

  return N;
}

int main() {
  int N = scan(), M = scan();

  for(int i = 1; i <= M; i++) L[i] = scan();
  for(int i = 1; i <= M; i++) C[i] = scan();
  for(int i = 1; i <= N; i++) A[i] = scan();

  int len = 0;
  for(int i = 1; i <= M; i++) {
    len += L[i];
    if(len > N) break;
  }
  if(len > N) {
    printf("0\n");
    return 0;
  }

  for(int i = 1; i <= N; i++) C2_map[i] = i;
  random_shuffle(C2_map + 1, C2_map + N + 1);

  long long req_sum = 0, req_sum2 = 0;
  for(int i = 1; i <= M; i++) {
    req_sum += 1LL * L[i] * C[i];
    req_sum2 += 1LL * L[i] * C2_map[C[i]];
  }

  long long sum = 0, sum2 = 0;
  int ans = 0;
  for(int i = 1; i < len; i++) {
    sum += A[i];
    sum2 += C2_map[A[i]];
  }
  for(int i = len; i <= N; i++) {
    sum += A[i];
    sum -= A[i - len];

    sum2 += C2_map[A[i]];
    sum2 -= C2_map[A[i - len]];

    if(sum == req_sum && sum2 == req_sum2) ans++;
  }

  printf("%d\n", ans);
}
