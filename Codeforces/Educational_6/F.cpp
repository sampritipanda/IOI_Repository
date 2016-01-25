#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct node {
  int L, R, i;
};

struct trie {
  trie* C[2] = {NULL, NULL};
  int cnt = 0;
};

int BLOCK_SIZE;
int A[50001];
int ans[5000];
vector<node> Q;
trie* root;
int curr_ans = 0;

bool compare(const node A, const node B) {
  int block_x = A.L/BLOCK_SIZE;
  int block_y = B.L/BLOCK_SIZE;

  if(block_x == block_y) return A.R < B.R;
  else block_x < block_y;
}

void insert(trie* curr, int x) {
  curr->cnt++;
  for(int i = 20; i >= 0; i--) {
    int bit;
    if(x & (1 << i)) {
      bit = 1;
    }
    else {
      bit = 0;
    }
    if(curr->C[bit] == NULL) curr->C[bit] = new trie;
    curr = curr->C[bit];
    curr->cnt++;
  }
}

void erase(trie* curr, int x) {
  curr->cnt--;
  for(int i = 20; i >= 0; i--) {
    int bit;
    if(x & (1 << i)) {
      bit = 1;
    }
    else {
      bit = 0;
    }
    curr = curr->C[bit];
    curr->cnt--;
  }
}

int find(trie* left, trie* right, int i) {
  if(i < 0) return 0;

  bool left_0, left_1, right_0, right_1;
  left_0 = left->C[0] != NULL && left->C[0]->cnt > 0;
  left_1 = left->C[1] != NULL && left->C[1]->cnt > 0;
  right_0 = right->C[0] != NULL && right->C[0]->cnt > 0;
  right_1 = right->C[1] != NULL && right->C[1]->cnt > 0;

  int ans = 0;
  if(left_0 && right_1 || right_0 && left_1) {
    if(left_0 && right_1)
      ans = max(ans, (1 << i) + find(left->C[0], right->C[1], i - 1));
    if(left_1 && right_0)
      ans = max(ans, (1 << i) + find(left->C[1], right->C[0], i - 1));
  }
  else if(left_1 && right_1 || left_0 && right_0) {
    if(left_0 && right_0)
      ans = max(ans, find(left->C[0], right->C[0], i - 1));
    if(left_1 && right_0)
      ans = max(ans, find(left->C[1], right->C[1], i - 1));
  }

  return ans;
}

void add(int x) {
  insert(root, x);
  curr_ans = max(curr_ans, find(root, root, 20));
}

void remove(int x) {
  erase(root, x);
  curr_ans = max(curr_ans, find(root, root, 20));
}

int main() {
  int N, M; cin >> N >> M;
  Q.resize(M);
  BLOCK_SIZE = int(sqrt(N));

  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 0; i < M; i++) {
    int L, R; cin >> Q[i].L >> Q[i].R;
    Q[i].i = i;
  }

  sort(Q.begin(), Q.end(), compare);

  root = new trie;
  int mo_left = 1, mo_right = 0;

  for(auto q: Q) {
    int L = q.L, R = q.R;

    while(mo_right < R) {
      mo_right++;
      add(A[mo_right]);
    }
    while(mo_right > R) {
      remove(A[mo_right]);
      mo_right--;
    }
    while(mo_left > L) {
      mo_left--;
      add(A[mo_left]);
    }
    while(mo_left < L) {
      remove(A[mo_left]);
      mo_left++;
    }

    ans[q.i] = curr_ans;
  }

  for(int i = 0; i < M; i++) cout << ans[i] << endl;
}
