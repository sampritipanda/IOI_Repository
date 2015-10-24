// Sort the Array

#include <iostream>
#include <algorithm>

using namespace std;

int A[100000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  if(is_sorted(A, A + N)) {
    cout << "yes" << endl;
    cout << "1 1" << endl;
  }
  else {
    int start_i, end_i;
    for(int i = 0; i < (N - 1); i++) {
      if(A[i] > A[i + 1]) {
        start_i = i; break;
      }
    }
    for(int i = N - 1; i > 0; i--) {
      if(A[i] < A[i - 1]) {
        end_i = i; break;
      }
    }

    reverse(A + start_i, A + end_i + 1);
    if(is_sorted(A, A + N)) {
      cout << "yes" << endl;
      cout << start_i + 1 << " " << end_i + 1 << endl;
    }
    else {
      cout << "no" << endl;
    }
  }
}
