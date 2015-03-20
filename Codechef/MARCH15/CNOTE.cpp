// Chef and Notebooks

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int X, Y, K, N; cin >> X >> Y >> K >> N;
    int P[N], C[N];
    for(int i = 0; i < N; i++) cin >> P[i] >> C[i];

    bool flag = false;

    for(int i = 0; i < N; i++){
      if(P[i] >= (X - Y) && C[i] <= K){
        flag = true;
        break;
      }
    }

    if(flag) cout << "LuckyChef" << endl;
    else cout << "UnluckyChef" << endl;
  }
}
