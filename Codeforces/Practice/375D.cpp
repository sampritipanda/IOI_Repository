#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100000;
int C[MAX + 1];
int F[MAX + 1];   // Frequency of color i
int SUF[MAX + 1]; // stores the number x such that F[x] >= i

struct ans_query {
  int L, R, K, i;
};

vector<int> G[MAX + 1];
int S[MAX + 1], E[MAX + 1], rev_S[MAX + 1];
int timer = 0;
int BLOCK_SIZE;
vector<ans_query> queries;
int ans[MAX + 1];

bool compare(ans_query A, ans_query B) {
  int i = A.L/BLOCK_SIZE, j = B.L/BLOCK_SIZE;
  if(i == j) return A.R < B.R;
  else return i < j;
}

void dfs(int i, int p) {
  S[i] = ++timer;
  rev_S[S[i]] = i;

  for(auto v: G[i]) {
    if(v == p) continue;
    dfs(v, i);
  }

  E[i] = timer;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  BLOCK_SIZE = int(sqrt(N));

  for(int i = 1; i <= N; i++) cin >> C[i];

  for(int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(1, 0);

  queries.resize(M);
  for(int i = 0; i < M; i++) {
    int V; cin >> V >> queries[i].K;
    queries[i].L = S[V]; queries[i].R = E[V];
    queries[i].i = i;
  }
  sort(queries.begin(), queries.end(), compare);

  int L = 1, R = 0;
  for(auto q: queries) {
    int qL = q.L, qR = q.R, K = q.K;

    while(R < qR) {
      R++;
      int curr_color = C[rev_S[R]];
      F[curr_color]++;
      SUF[F[curr_color]]++;
    }
    while(R > qR) {
      int curr_color = C[rev_S[R]];
      SUF[F[curr_color]]--;
      F[curr_color]--;
      R--;
    }

    while(L < qL) {
      int curr_color = C[rev_S[L]];
      SUF[F[curr_color]]--;
      F[curr_color]--;
      L++;
    }
    while(L > qL) {
      L--;
      int curr_color = C[rev_S[L]];
      F[curr_color]++;
      SUF[F[curr_color]]++;
    }

    ans[q.i] = SUF[K];
  }

  for(int i = 0; i < M; i++) cout << ans[i] << endl;
}
