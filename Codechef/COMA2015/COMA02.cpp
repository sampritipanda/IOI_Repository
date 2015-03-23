#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N, M, O; cin >> N >> M >> O;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    bool chef = A[0] >= O;
    int count = 0;
    for(int i = 0; i < N; i++){
      count += (A[i] >= O);
    }
    if(chef){
      cout << min(count, M) << endl;
    }
    else cout << -1 << endl;
  }
}
