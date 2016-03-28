#include <iostream>

using namespace std;

int A[100000];

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
      sum += A[i];
    }
    if(sum % N != 0) cout << "No Treat" << endl;
    else {
      int req = sum/N;
      long long cnt = 0;
      for(int i = 0; i < N; i++) {
        cnt += abs(A[i] - req);
      }
      cout << cnt/2 << endl;
    }
  }
}
