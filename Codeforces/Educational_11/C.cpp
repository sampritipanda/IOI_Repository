#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[300001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  int max_len = 0, start = -1, end = -1;
  int L = 0, R = -1, curr_used = 0;
  while(R < N) {
    if(R <= L) {
      R++;
      if(R == N) break;
      if(A[R] == 0) {
        if(curr_used == K) {
          if(R == L) {
            L = R + 1;
          }
          else {
            L = R;
            R = L - 1;
          }
          curr_used = 0;
          continue;
        }
        curr_used++;
      }
    }
    else {
      if(R == N - 1) break;
      if(curr_used < K || (curr_used == K && A[R + 1] == 1)) {
        R++;
        if(A[R] == 0) curr_used++;
      }
      else {
        if(A[L] == 0) curr_used--;
        L++;
      }
    }

    if(R - L + 1 > max_len) {
      max_len = R - L + 1;
      start = L;
      end = R;
    }
  }

  if(R == N - 1 && R - L + 1 > max_len) {
    max_len = R - L + 1;
    start = L;
    end = R;
  }

  cout << max_len << endl;
  if(start >= 0) {
    for(int i = start; i <= end; i++) {
      if(A[i] == 0) A[i] = 1;
    }
  }
  for(int i = 0; i < N; i++) cout << A[i] << " ";
  cout << endl;
}
