#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int X[100001];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    X[x]++;
  }

  for(int i = 1; i <= N; i++) {
    if(X[i] == 0) cout << i << " ";
  }
  cout << endl;
}
