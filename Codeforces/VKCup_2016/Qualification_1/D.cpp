#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int A[200001];
vector<pair<string, int> > ans;

int main() {
  int N, M, s, d; cin >> N >> M >> s >> d;
  for(int i = 1; i <= N; i++) cin >> A[i];
  sort(A + 1, A + 1 + N);

  bool pos = true;

  int i = 1;
  int x = 0;
  while(i <= N) {
    int run_till = A[i] - 1;

    int j = i;
    while(j + 1 <= N && (A[j + 1] - 1) - (A[j] + 1) < s) j++;

    int jump_till = A[j] + 1;

    if(run_till - x < s || jump_till - run_till > d) {
      pos = false;
      break;
    }

    ans.push_back({"RUN", run_till - x});
    ans.push_back({"JUMP", jump_till - run_till});

    x = jump_till;
    i = j + 1;
  }

  if(x < M) ans.push_back({"RUN", M - x});

  if(pos) {
    for(auto it: ans) cout << it.first << " " << it.second << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }
}

