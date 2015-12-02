#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, B;

int main() {
  int N, M; cin >> N >> M;

  for(int i = 0; i < N; i++) {
    int a; cin >> a; A.push_back(a);
  }
  for(int i = 0; i < M; i++) {
    int a; cin >> a; B.push_back(a);
  }

  sort(A.begin(), A.end());

  for(int i = 0; i < M; i++) {
    cout << upper_bound(A.begin(), A.end(), B[i]) - A.begin() << " ";
  }
  cout << endl;
}
