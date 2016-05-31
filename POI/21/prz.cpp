#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

inline int scan() {
  int N = 0;
  char c = getchar_unlocked();
  while(c < '0' || c > '9') {
    c = getchar_unlocked();
  }

  while(c >= '0' && c <= '9') {
    N = (N<<1) + (N<<3) + c - '0';
    c = getchar_unlocked();
  }

  return N;
}

int C[1000001];
vector<int> I[1000001];
int X[1000001]; int R_X[1000001];
int Y[1000001]; int R_Y[1000001];
bool dp_for[1000001]; int dp_for_start[1000001];
bool dp_back[1000001]; int dp_back_start[1000001];
int dp_start_house[1000001];
vector<int> ans;

int main() {
  int N = scan(), K = scan();

  for(int i = 1; i <= N; i++) {
    C[i] = scan();
    I[C[i]].push_back(i);
  }

  int M = scan(), L = scan();

  for(int i = 1; i <= M; i++) {
    X[i] = scan();
    R_X[X[i]] = i;
  }
  for(int i = 1; i <= L; i++) {
    Y[i] = scan();
    R_Y[Y[i]] = i;
  }

  for(int i = 2; i <= N - 1; i++) {
    int ind = R_X[C[i]];
    if(ind == 0) continue;
    if(ind == 1) {
      dp_for[i] = true;
      dp_for_start[i] = i;
      continue;
    }

    int prev = X[ind - 1];
    if(I[prev].size() == 0) continue;
    vector<int>::iterator it = lower_bound(I[prev].begin(), I[prev].end(), i);
    if(it == I[prev].begin()) continue;

    it--;
    dp_for[i] = dp_for[*it];
    dp_for_start[i] = dp_for_start[*it];
  }

  for(int i = N - 1; i >= 2; i--) {
    int ind = R_Y[C[i]];
    if(ind == 0) continue;
    if(ind == 1) {
      dp_back[i] = true;
      dp_back_start[i] = i;
      continue;
    }

    int prev = Y[ind - 1];
    if(I[prev].size() == 0) continue;
    vector<int>::iterator it = upper_bound(I[prev].begin(), I[prev].end(), i);
    if(it == I[prev].end()) continue;

    dp_back[i] = dp_back[*it];
    dp_back_start[i] = dp_back_start[*it];
  }

  for(int i = 1; i <= N; i++) {
    dp_start_house[i] = max(dp_start_house[i - 1], I[C[i]].back());
  }

  int meet_color = X[M];

  for(int i = 1; i <= N; i++) {
    if(C[i] == meet_color && dp_for[i] && dp_back[i]) {
      int left = dp_for_start[i] - 1, right = dp_back_start[i] + 1;
      if(right <= dp_start_house[left]) {
        ans.push_back(i);
      }
    }
  }

  printf("%d\n", int(ans.size()));
  for(int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    if(i == int(ans.size()) - 1) printf("\n");
    else printf(" ");
  }
}
