#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int P[300001];
vector<int> I[300001];
vector<int> check[300001];
int Q[300001][3];
int L[300001], R[300001];
long long bit[300002];
int N, M, K;

void update(int i, long long x) {
  while(i <= M) {
    bit[i] += x;
    i += i & -i;
  }
}

inline void range_update(int L, int R, long long x) {
  update(L, x);
  update(R + 1, -x);
}

long long query(int i) {
  long long ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

int main() {
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= M; i++) {
    int t; scanf("%d", &t);
    I[t].push_back(i);
  }

  for(int i = 1; i <= N; i++) scanf("%d", &P[i]);

  scanf("%d", &K);
  for(int i = 1; i <= K; i++) {
    int L, R, A; scanf("%d %d %d", &Q[i][0], &Q[i][1], &Q[i][2]);
  }

  for(int i = 1; i <= N; i++) {
    L[i] = 1;
    R[i] = K + 1;
  }

  for(int t = 0; t < 20; t++) {
    for(int i = 1; i <= M; i++) bit[i] = 0;
    for(int i = 1; i <= N; i++) {
      if(L[i] < R[i]) {
        int mid = (L[i] + R[i])/2;
        check[mid].push_back(i);
      }
    }

    for(int i = 1; i <= K; i++) {
      if(Q[i][0] <= Q[i][1]) {
        range_update(Q[i][0], Q[i][1], Q[i][2]);
      }
      else {
        range_update(1, Q[i][1], Q[i][2]);
        range_update(Q[i][0], M, Q[i][2]);
      }

      while(check[i].size() > 0) {
        int x = check[i].back();
        check[i].pop_back();

        long long samples = 0;
        for(int j = 0; j < I[x].size(); j++) {
          samples += query(I[x][j]);
          if(samples >= P[x]) break;
        }

        if(samples >= P[x]) {
          R[x] = i;
        }
        else {
          L[x] = i + 1;
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(L[i] == K + 1) printf("NIE\n");
    else printf("%d\n", L[i]);
  }
}
