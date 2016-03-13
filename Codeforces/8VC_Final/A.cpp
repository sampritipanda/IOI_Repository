#include <iostream>
#include <algorithm>

using namespace std;

int A[4000001];
int B[2000001];

int main() {
  int N; cin >> N;

  for(int i = 1; i <= N - 1; i++) {
    int x; cin >> x;
    if(x == 0) {
      i--;
    }
    else {
      A[i] = x;
    }
  }

  for(int i = 1; i <= N - 1; i++) {
    int x; cin >> x;
    if(x == 0) {
      i--;
    }
    else {
      B[i] = x;
    }
  }

  N--;
  for(int i = N + 1; i <= 2 * N; i++) A[i] = A[i - N];

  int pos = -1;
  for(int i = 1; i <= N; i++) {
    if(A[i] == B[1]) {
      pos = i;
      break;
    }
  }

  bool done = true;
  for(int i = pos; i <= pos + N - 1; i++) {
    if(A[i] != B[i - pos + 1]) {
      done = false;
      break;
    }
  }

  if(done) cout << "YES" << endl;
  else cout << "NO" << endl;
}

