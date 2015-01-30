// Cricket Tournament

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int max_fluc = INT_MIN, min_elem = INT_MAX;
    for(int i = 0; i < N; i++){
      if(A[i] - min_elem > max_fluc) max_fluc = A[i] - min_elem;

      bool curr_max = false;
      if(A[i] < min_elem) {
        min_elem = A[i];
        curr_max = true;
      }

      if(!curr_max && (A[i] - min_elem > max_fluc)) max_fluc = A[i] - min_elem;
    }
    cout << max_fluc << endl;
  }
}
