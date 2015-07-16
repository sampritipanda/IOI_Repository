// Chefs and Voting for best friend 

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int C[N], used[N];
    for(int i = 0; i < N; i++) {
      used[i] = 0;
    }
    for(int i = 0; i < N; i++) cin >> C[i];

    bool possible = true;
    int vote_sum = 0, j = 0;
    for(int i = 0; i < N; i++) {
      vote_sum += C[i];
      if(C[i] == N) {
        possible = false;
      }
    }
    if(vote_sum != N) possible = false;

    if(possible) {
      for(int i = 0; i < N; i++) {
        int q = i + 1;
        while(1) {
          if(q == N){
            q = 0;
            continue;
          }
          else {
            if(C[q++] > 0) {
              C[q - 1]--;
              used[i] = q;
              break;
            }
            else {
              continue;
            }
          }
        }
      }

      for(int i = 0; i < N; i++) cout << used[i] << " \n"[i == (N - 1)];
    }
    else {
      cout << -1 << endl;
    }
  }
}
