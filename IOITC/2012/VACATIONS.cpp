#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int BLOCK_SIZE;
struct query {
  int L, R;
  int ind;
};
vector<query> queries;
int A[30001];
int ans[200001];
int freq[1000001];

bool compare(query A, query B) {
  if(A.L/BLOCK_SIZE == B.L/BLOCK_SIZE) return A.R < B.R;
  else return A.L/BLOCK_SIZE < B.L/BLOCK_SIZE;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;

  BLOCK_SIZE = int(floor(sqrt(N)));
  for(int i = 1; i <= N; i++) cin >> A[i];

  int Q; cin >> Q;
  queries.resize(Q);

  for(int i = 0; i < Q; i++) {
    cin >> queries[i].L >> queries[i].R;
    queries[i].ind = i;
  }

  sort(queries.begin(), queries.end(), compare);

  int mo_left = 1, mo_right = 0;
  int curr_ans = 0;

  for(int i = 0; i < Q; i++) {
    int L = queries[i].L, R = queries[i].R;

    while(mo_right < R) {
      mo_right++;
      freq[A[mo_right]]++;
      if(freq[A[mo_right]] == 1) curr_ans++;
    }
    while(mo_right > R) {
      freq[A[mo_right]]--;
      if(freq[A[mo_right]] == 0) curr_ans--;
      mo_right--;
    }

    while(mo_left < L) {
      freq[A[mo_left]]--;
      if(freq[A[mo_left]] == 0) curr_ans--;
      mo_left++;
    }
    while(mo_left > L) {
      mo_left--;
      freq[A[mo_left]]++;
      if(freq[A[mo_left]] == 1) curr_ans++;
    }

    ans[queries[i].ind] = curr_ans;
  }

  for(int i = 0; i < Q; i++) cout << ans[i] << endl;
}
