#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool C[20][20];

int main() {
  memset(C, false, sizeof C);

  int N, M; cin >> N >> M;

  for(int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    C[a][b] = C[b][a] = true;
  }

  int count = 0;
  for(int mask = 0; mask < (1 << N); mask++) {
    vector<int> A;
    for(int i = 0; i < N; i++) {
      if(mask & (1 << i)) A.push_back(i);
    }

    bool pos = true;
    for(int i = 0; i < A.size(); i++) {
      for(int j = i + 1; j < A.size(); j++) {
        if(C[A[i]][A[j]]) {
          pos = false;
          break;
        }
      }
      if(!pos) break;
    }

    if(pos) count++;
  }

  cout << count << endl;
}
