// Puppy and cats 

#include <iostream>
#include <algorithm>

using namespace std;

bool cats[501][501];

int main() {
  int T; cin >> T;

  while(T--) {
    int N, K; cin >> N >> K;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cats[i][j] = false;
      }
    }

    while(K--) {
      int x, y; cin >> x >> y;

      int i = x, j = y;
      while(i <= N && j <= N) {
        cats[i][j] = true;
        i += 1; j += 1;
      }

      i = x, j = y;
      while(i >= 1 && j >= 1) {
        cats[i][j] = true;
        i -= 1; j -= 1;
      }

      i = x, j = y;
      while(i >= 1 && j <= N) {
        cats[i][j] = true;
        i -= 1; j += 1;
      }

      i = x, j = y;
      while(i <= N && j >= 1) {
        cats[i][j] = true;
        i += 1; j -= 1;
      }
    }

    int count = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(!cats[i][j]) count++;
      }
    }


    cout << count << endl;
  }
}
