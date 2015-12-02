#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int A[100001];
multiset<int> X;

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int ans = 0;
  int i = 1, j = 1;
  X.insert(A[i]);

  while(i < N && j < N) {
    if(*X.rbegin() - *X.begin() <= 1) ans = max(ans, j - i + 1);

    if(i == j) {
      j += 1;
      X.insert(A[j]);
    }
    else {
      X.insert(A[j + 1]);
      int a = *X.rbegin() - *X.begin();
      X.erase(X.find(A[j + 1]));

      X.erase(X.find(A[i]));
      int b = *X.rbegin() - *X.begin();
      X.insert(A[i]);

      if(a <= 1) {
        j++;
        X.insert(A[j]);
      }
      else {
        X.erase(X.find(A[i]));
        i++;
      }
    }
  }

  while(i <= N) {
    if(*X.rbegin() - *X.begin() <= 1) ans = max(ans, j - i + 1);
    if(X.count(A[i]) > 0) X.erase(X.find(A[i]));
    i++;
  }

  cout << ans << endl;
}
