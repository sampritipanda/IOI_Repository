#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int X[50000], Y[50000];
int W[1000000], S[1000000];
int picked[1000000];  // 0 = not picked, 1 = in queue, 2 = picked
int A, B, T;
int sorted_toys[1000000];  // inc W[i], dec S[i];
priority_queue<pair<int, int> > Q;

bool check(int time) {
  while(!Q.empty()) Q.pop();
  for(int i = 0; i < T; i++) picked[i] = 0;

  int i = 0;
  for(int j = 0; j < A; j++) {
    while(i < T && W[sorted_toys[i]] < X[j]) {
      Q.push({S[sorted_toys[i]], sorted_toys[i]});
      picked[sorted_toys[i]] = 1;
      i++;
    }
    for(int k = 0; k < time; k++) {
      if(Q.empty()) break;
      auto it = Q.top(); Q.pop();
      picked[it.second] = 2;
    }
  }

  for(int i = 0; i < T; i++) {
    if(picked[i] == 0) Q.push({S[i], i});
  }

  for(int j = B - 1; j >= 0; j--) {
    for(int k = 0; k < time; k++) {
      if(Q.empty()) break;
      auto it = Q.top(); Q.pop();
      if(it.first >= Y[j]) continue;
      picked[it.second] = 2;
    }
  }

  for(int i = 0; i < T; i++) {
    if(picked[i] != 2) return false;
  }
  return true;
}

int main() {
  scanf("%d %d %d", &A, &B, &T);

  for(int i = 0; i < A; i++) scanf("%d", &X[i]);
  for(int i = 0; i < B; i++) scanf("%d", &Y[i]);

  sort(X, X + A);
  sort(Y, Y + B);

  for(int i = 0; i < T; i++) {
    scanf("%d %d", &W[i], &S[i]);
    sorted_toys[i] = i;
  }
  sort(sorted_toys, sorted_toys + T, [](int a, int b) {
      if(W[a] == W[b]) {
        return S[a] > S[b];
      }
      return W[a] < W[b];
  });

  bool pos = true;
  for(int i = 0; i < T; i++) {
    if(upper_bound(X, X + A, W[i]) == (X + A) && upper_bound(Y, Y + B, S[i]) == (Y + B)) {
      pos = false;
      break;
    }
  }

  if(!pos) {
    printf("-1\n");
    return 0;
  }

  int L = 1, R = T;
  while(L < R) {
    int mid = (L + R)/2;
    if(check(mid)) {
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }

  printf("%d\n", L);
}
