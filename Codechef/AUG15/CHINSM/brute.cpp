// Chef and insomnia

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool bad[100][100];
int A[100];

int main() {
  memset(bad, false, sizeof bad);

  int N, K; cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> A[i];

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i < j && A[i] % A[j] == K) bad[i][j] = true;
    }
  }

  int count = 0;
  for(int len = 1; len <= N; len++) {
    for(int i = 0; i < (N - len + 1); i++) {
      bool good = true;
      for(int j = i; j <= (i + len - 1); j++) {
        for(int k = i; k < j; k++) {
          if(bad[k][j]) {
            good = false;
            break;
          }
        }
        if(!good) break;
      }
      if(good) count++;
    }
  }

  cout << count << endl;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(bad[i][j]) cout << i << " " << j << endl;
    }
  }
}
