#include <iostream>
#include <algorithm>

using namespace std;

char A[1401][1401];
int N;

int find(char c) {
  int ans = 0;

  for(int i = 1; i <= N; i++) {
    int curr = 0;
    for(int j = 1; j <= N; j++) {
      if(A[i][j] == c) curr++;
      else curr = 0;

      ans = max(ans, curr);
    }
  }

  for(int j = 1; j <= N; j++) {
    int curr = 0;
    for(int i = 1; i <= N; i++) {
      if(A[i][j] == c) curr++;
      else curr = 0;

      ans = max(ans, curr);
    }
  }

  for(int j2 = 1; j2 <= N; j2++) {
    int i = 1, j = j2;
    int curr = 0;
    while(i <= N && j <= N) {
      if(A[i][j] == c) curr++;
      else curr = 0;
      ans = max(ans, curr);

      i += 1; j += 1;
    }
  }

  for(int i2 = 2; i2 <= N; i2++) {
    int j = 1, i = i2;
    int curr = 0;
    while(i <= N && j <= N) {
      if(A[i][j] == c) curr++;
      else curr = 0;
      ans = max(ans, curr);

      i += 1; j += 1;
    }
  }

  for(int j2 = N; j2 >= 1; j2--) {
    int i = 1, j = j2;
    int curr = 0;
    while(i <= N && j >= 1) {
      if(A[i][j] == c) curr++;
      else curr = 0;
      ans = max(ans, curr);

      i += 1; j -= 1;
    }
  }

  for(int i2 = 2; i2 <= N; i2++) {
    int j = N, i = i2;
    int curr = 0;
    while(i <= N && j >= 1) {
      if(A[i][j] == c) curr++;
      else curr = 0;
      ans = max(ans, curr);

      i += 1; j -= 1;
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  int a = find('s'), b = find('S');

  if(a > b) cout << 's';
  else if(a < b) cout << 'S';
  else cout << '?';
  cout << endl;

  cout << max(a, b) << endl;
}
