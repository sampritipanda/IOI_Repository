#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1000001];
int N, K;
vector<pair<int, int > > I; // {color, index} 
vector<vector<int> > ans;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K;
  string S; cin >> S;

  for(int i = 0; i < N; i++) {
    if(S[i] == 'b') A[i + 1] = 0;
    else A[i + 1] = 1;

    I.push_back(make_pair(A[i + 1], i + 1));
  }

  while(!I.empty()) {
    for(int i = 0; i + (K + 1) <= I.size(); i++) {
      int S[2] = {0, 0};
      for(int j = i; j < i + (K + 1); j++) {
        S[I[j].first]++;
      }
      if(S[0] == K && S[1] == 1) {
        ans.push_back(vector<int>());
        for(int j = i; j < i + (K + 1); j++) ans.back().push_back(I[j].second);
        I.erase(I.begin() + i, I.begin() + (i + K + 1));
        break;
      }
    }
  }

  for(int i = ans.size() - 1; i >= 0; i--) {
    for(int j = 0; j < (K + 1); j++) {
      cout << ans[i][j] << " " ;
    }
    cout << endl;
  }
}

