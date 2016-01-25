#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int A[1000001];
map<int, int> M;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  int i = 1, j = 1;
  M[A[i]]++;
  int L = 1, R = 1;

  while(true) {
    int new_count = M.size();

    if(new_count <= K && j - i + 1 > R - L + 1) L = i, R = j;
    if(j == N) break;

    if(M.count(A[j + 1]) == 0) new_count++;

    if(i < j && new_count > K) {
      M[A[i]]--;
      if(M[A[i]] == 0) M.erase(A[i]);
      i++;
    }
    else {
      M[A[j + 1]]++;
      j++;
    }
  }

  cout << L << " " << R << endl;
}
