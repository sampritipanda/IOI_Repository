#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct node {
  int L, R, i;
};

int A[100001];
int P[100001];
long long ans[100000];
vector<node> Q;
int BLOCK_SIZE;
int freq[1 << 20];
long long curr_ans;
int K;

bool compare(const node A, const node B) {
  int block_A = A.L/BLOCK_SIZE;
  int block_B = B.L/BLOCK_SIZE;

  if(block_A == block_B) return A.R < B.R;
  return block_A < block_B;
}

void add(int x) {
  curr_ans += freq[x ^ K];
  freq[x]++;
}

void remove(int x) {
  freq[x]--;
  curr_ans -= freq[x ^ K];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, M; cin >> N >> M >> K;
  BLOCK_SIZE = int(sqrt(N));
  Q.resize(M);

  for(int i = 1; i <= N; i++) cin >> A[i];
  P[1] = A[1]; for(int i = 2; i <= N; i++) P[i] = P[i - 1] ^ A[i];

  for(int i = 0; i < M; i++) {
    cin >> Q[i].L >> Q[i].R; Q[i].i = i;
  }

  sort(Q.begin(), Q.end(), compare);

  int mo_left = 0, mo_right = 0;
  curr_ans = 0;
  freq[0] = 1;

  for(auto q: Q) {
    int L = q.L, R = q.R;

    while(mo_right < R) {
      mo_right++;
      add(P[mo_right]);
    }
    while(mo_right > R) {
      remove(P[mo_right]);
      mo_right--;
    }
    while(mo_left < L - 1) {
      remove(P[mo_left]);
      mo_left++;
    }
    while(mo_left > L - 1) {
      mo_left--;
      add(P[mo_left]);
    }

    ans[q.i] = curr_ans;
  }

  for(int i = 0; i < M; i++) cout << ans[i] << endl;
}
