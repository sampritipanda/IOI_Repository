#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int F[100001], B[100001];
vector<int> I[100001];

int main() {
  int N, M; cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    cin >> F[i];
    I[F[i]].push_back(i);
  }

  for(int i = 1; i <= M; i++) {
    cin >> B[i];
  }

  for(int i = 1; i <= M; i++) {
    if(I[B[i]].size() == 0) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  for(int i = 1; i <= M; i++) {
    if(I[B[i]].size() > 1) {
      cout << "Ambiguity" << endl;
      return 0;
    }
  }

  cout << "Possible" << endl;
  for(int i = 1; i <= M; i++) cout << I[B[i]][0] << " ";
  cout << endl;
}
