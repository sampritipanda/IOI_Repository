#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int max_length = 1, curr_length = 1;
  for(int i = 0; i < (N - 1); i++) {
    if(A[i] <= A[i + 1]) {
      curr_length++;
      max_length = max(max_length, curr_length);
    }
    else {
      curr_length = 1;
    }
  }

  cout << max_length << endl;
}
