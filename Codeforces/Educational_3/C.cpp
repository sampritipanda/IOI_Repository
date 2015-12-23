#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;

  vector<int> A(N), B(N);
  vector<pair<int, int> > T;

  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
    T.push_back({A[i], i});
  }

  sort(T.begin(), T.end());
  reverse(T.begin(), T.end());

  for(int i = 0; i < N; i++) B[i] = sum/N;

  for(int i = 0; i < sum % N; i++) B[T[i].second] += 1;

  int sum_2 = 0;
  for(int i = 0; i < N; i++) sum_2 += abs(A[i] - B[i]);
  cout << sum_2/2 << endl;
}
