#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

struct query {
  int L, R, i;
};

int A[100001];
vector<query> queries;
int BLOCK_SIZE;
int ans[100001];
int freq[100001];
int curr_ans = 0;

bool compare(query A, query B) {
  if(A.L/BLOCK_SIZE == B.L/BLOCK_SIZE) return A.R < A.L;
  else return A.L/BLOCK_SIZE < B.L/BLOCK_SIZE;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M;
  BLOCK_SIZE = int(sqrt(N));

  for(int i = 1; i <= N; i++) cin >> A[i];

  queries.resize(M);
  for(int i = 0; i < M; i++) {
    int L, R; cin >> queries[i].L >> queries[i].R;
    queries[i].i = i;
  }

  sort(queries.begin(), queries.end(), compare);

  int L = 1, R = 0;
  for(auto Q: queries) {
    int currL = Q.L, currR = Q.R;

    while(R < currR) {
      R++;
      if(A[R] <= N) {
        freq[A[R]]++;
        if(freq[A[R]] == A[R]) curr_ans++;
        else if(freq[A[R]] == A[R] + 1) curr_ans--;
      }
    }

    while(R > currR) {
      if(A[R] <= N) {
        freq[A[R]]--;
        if(freq[A[R]] == A[R]) curr_ans++;
        else if(freq[A[R]] == A[R] - 1) curr_ans--;
      }
      R--;
    }

    while(L < currL) {
      if(A[L] <= N) {
        freq[A[L]]--;
        if(freq[A[L]] == A[L]) curr_ans++;
        else if(freq[A[L]] == A[L] - 1) curr_ans--;
      }
      L++;
    }

    while(L > currL) {
      L--;
      if(A[L] <= N) {
        freq[A[L]]++;
        if(freq[A[L]] == A[L]) curr_ans++;
        else if(freq[A[L]] == A[L] + 1) curr_ans--;
      }
    }

    ans[Q.i] = curr_ans;
  }

  for(int i = 0; i < M; i++) cout << ans[i] << endl;
}
