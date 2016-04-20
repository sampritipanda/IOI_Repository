#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L[101];
int R[101];

bool compare(vector<int> A, vector<int> B) {
  if(A[0] == B[0]) {
    if(A[1] == B[1]) return A[2] < B[2];
    return A[1] > B[1];
  }
  return A[0] > B[0];
}

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    for(int i = 1; i <= N; i++) cin >> L[i];
    for(int i = 1; i <= N; i++) cin >> R[i];

    vector<vector<int> > A;
    for(int i = 1; i <= N; i++) {
      A.push_back({L[i] * R[i], R[i], i});
    }
    sort(A.begin(), A.end(), compare);

    cout << A[0][2] << endl;
  }
}
