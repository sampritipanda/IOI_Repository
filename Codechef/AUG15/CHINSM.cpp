// Chef and insomnia

#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

int A[100000];
int min_bad[100000];
unordered_map<int, int> index;

int main() {
  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) min_bad[i] = N;

  for(int i = N - 1; i >= 0; i--) {
    int div = abs(A[i] - K);
    if(div == 0) continue;

    for(int j = 1; j <= sqrt(div); j++) {
      if(div % j != 0) continue;

      if(A[i] % j == K && index.count(j) > 0) min_bad[i] = min(min_bad[i], index[j] - 1);
      if(A[i] % (div/j) == K && index.count(div/j) > 0) min_bad[i] = min(min_bad[i], index[div/j] - 1);
    }

    index[A[i]] = i + 1;
  }

  stack<int> V;
  for(int i = N - 1; i >= 0; i--) {
    while(!V.empty() && A[V.top()] <= A[i]) V.pop();

    if(A[i] - K == 0 && !V.empty()) {
      min_bad[i] = V.top();
    }

    V.push(i);
  }

  for(int i = N - 2; i >= 0; i--) min_bad[i] = min(min_bad[i + 1], min_bad[i]);

  long long count = 0;
  for(int i = N - 1; i >= 0; i--) {
    count += min_bad[i] - i;
  }
  cout << count << endl;
}
