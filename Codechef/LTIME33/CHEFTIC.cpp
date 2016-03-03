#include <iostream>

using namespace std;

int N, K;
char A[21][21];

bool check() {
  for(int i = 1; i <= N; i++) {
    int curr = 0;
    for(int j = 1; j <= N; j++) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;

      if(curr == K) return true;
    }
  }

  for(int j = 1; j <= N; j++) {
    int curr = 0;
    for(int i = 1; i <= N; i++) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;

      if(curr == K) return true;
    }
  }

  for(int j2 = 1; j2 <= N; j2++) {
    int i = 1, j = j2;
    int curr = 0;
    while(i <= N && j <= N) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;
      if(curr == K) return true;

      i += 1; j += 1;
    }
  }

  for(int i2 = 2; i2 <= N; i2++) {
    int j = 1, i = i2;
    int curr = 0;
    while(i <= N && j <= N) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;
      if(curr == K) return true;

      i += 1; j += 1;
    }
  }

  for(int j2 = N; j2 >= 1; j2--) {
    int i = 1, j = j2;
    int curr = 0;
    while(i <= N && j >= 1) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;
      if(curr == K) return true;

      i += 1; j -= 1;
    }
  }

  for(int i2 = 2; i2 <= N; i2++) {
    int j = N, i = i2;
    int curr = 0;
    while(i <= N && j >= 1) {
      if(A[i][j] == 'X') curr++;
      else curr = 0;
      if(curr == K) return true;

      i += 1; j -= 1;
    }
  }

  return false;
}

string solve() {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(A[i][j] == '.') {
        A[i][j] = 'X';

        if(check()) {
          return "YES";
        }

        A[i][j] = '.';
      }
    }
  }

  return "NO";
}

int main() {
  int T; cin >> T;

  while(T--) {
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cin >> A[i][j];
      }
    }

    cout << solve() << endl;
  }
}
