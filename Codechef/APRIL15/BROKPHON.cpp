// Broken Telephone

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    int A[N]; for(int i = 0; i < N; i++) cin >> A[i];

    int count = 0;
    if(N > 1) count += (A[0] != A[1]);
    if(N > 1) count += (A[N - 1] != A[N - 2]);
    for(int i = 1; i < (N - 1); i++){
      if(A[i] != A[i - 1] || A[i] != A[i + 1]) count++;
    }

    cout << count << endl;
  }
}
