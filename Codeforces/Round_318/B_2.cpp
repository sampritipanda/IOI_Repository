#include <iostream>
#include <algorithm>

using namespace std;

int A[100001], B[100001];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> A[i];
  long long sum = 0;
  for(int i = 1; i <= N; i++) {
    sum++;
    B[i] = sum = min((long long)A[i], sum);
  }
  sum = 0;
  for(int i = N; i >= 1; i--) {
    sum++;
    B[i] = min((long long)B[i], sum = min((long long)A[i], sum));
  }
  cout << *max_element(B + 1, B + N + 1) << endl;
}
