#include <iostream>
#include <algorithm>

using namespace std;

int A[200001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N/2; i++) {
    if(i % 2 == 1) {
      swap(A[i], A[N - i + 1]);
    }
  }

  for(int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
}
