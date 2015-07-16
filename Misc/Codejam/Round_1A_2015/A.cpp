// Mushroom Monster

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    int N; cin >> N;
    int A[N]; for(int i = 0; i < N; i++) cin >> A[i];
    int y = 0, z = 0;

    int prev = 0;
    for(int i = 0; i < N; i++){
      if(A[i] < prev) y += (prev - A[i]);
      prev = A[i];
    }

    int max_rate = 0;
    for(int i = 1; i < N; i++) max_rate = max(max_rate, A[i - 1] - A[i]);
    for(int i = 0; i < (N - 1); i++){
      if(A[i] > max_rate) z += max_rate;
      else z += A[i];
    }

    cout << "Case #" << t << ": " << y << " " << z << endl;
  }
}
