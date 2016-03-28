#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct query {
  int L, R, i;
};

long long A[200001];
int BLOCK_SIZE;
vector<query> queries;
int freq[1000001];
long long curr_ans = 0;
long long ans[200001];

bool compare(query A, query B) {
  int block_A = A.L/BLOCK_SIZE, block_B = B.L/BLOCK_SIZE;

  if(block_A == block_B) return A.R < B.R;
  else return block_A < block_B;
}

int main() {
  int N, T; scanf("%d %d", &N, &T);
  BLOCK_SIZE = int(sqrt(N));

  for(int i = 1; i <= N; i++) scanf("%I64d", &A[i]);

  queries.resize(T);
  for(int i = 0; i < T; i++) {
    scanf("%d %d", &queries[i].L, &queries[i].R);
    queries[i].i = i;
  }

  sort(queries.begin(), queries.end(), compare);

  int L = 1, R = 0;
  for(auto Q: queries) {
    int currL = Q.L, currR = Q.R;

    while(R < currR) {
      R++;
      curr_ans += (2 * freq[A[R]] + 1) * A[R];
      freq[A[R]]++;
    }

    while(R > currR) {
      curr_ans -= (2 * freq[A[R]] - 1) * A[R];
      freq[A[R]]--;
      R--;
    }

    while(L < currL) {
      curr_ans -= (2 * freq[A[L]] - 1) * A[L];
      freq[A[L]]--;
      L++;
    }

    while(L > currL) {
      L--;
      curr_ans += (2 * freq[A[L]] + 1) * A[L];
      freq[A[L]]++;
    }

    ans[Q.i] = curr_ans;
  }

  for(int i = 0; i < T; i++) printf("%I64d\n", ans[i]);
}
