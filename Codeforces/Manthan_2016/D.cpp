#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N;
int A[1000];
map<int, int> B;
set<pair<int, int> > done;

int main() {
  cin >> N;
  for(int i = 0 ; i < N; i++) {
    cin >> A[i];
    B[A[i]]++;
  }

  int ans = 2;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(j == i) continue;

      map<int, int> B2;

      int f1 = A[i], f2 = A[j];

      if(done.count({f1, f2})) continue;
      done.insert({f1, f2});

      B2[f1]++; B2[f2]++;
      int size = 2;
      while(B2[f1 + f2] < B[f1 + f2]) {
        size++;
        B2[f1 + f2]++;
        int s = f1 + f2;
        f1 = f2, f2 = s;
      }
      ans = max(ans, size);
    }
  }

  cout << ans << endl;
}
