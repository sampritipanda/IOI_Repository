#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

struct block {
  vector<int> data;
  int freq[100001];

  block() {
    data.clear();
    memset(freq, 0, sizeof freq);
  }

  int sz() {
    return data.size();
  }

  void erase(int i) {
    int el = data[i];
    freq[el]--;
    data.erase(data.begin() + i);
  }

  void append(int x) {
    data.push_back(x);
    freq[x]++;
  }

  void insert(int i, int x) {
    data.insert(data.begin() + i, x);
    freq[x]++;
  }
};

int A[100000];
int BLOCK_SIZE;
vector<block> blocks;
int N, B;

// Returns block_id and index in block
pair<int, int> find_block(int ind) {
  int L = 0;
  for(int i = 0; i < B; i++) {
    int R = L + blocks[i].sz() - 1;
    if(ind >= L && ind <= R) {
      return {i, ind - L};
    }
    L = R + 1;
  }

  return {-1, -1};
}

void flatten() {
  int ind = 0;
  for(int i = 0; i < B; i++) {
    for(auto j: blocks[i].data) {
      A[ind++] = j;
    }
  }
  assert(ind == N);
}

void decompose() {
  for(int i = 0; i < B; i++) {
    memset(blocks[i].freq, 0, sizeof blocks[i].freq);
    blocks[i].data.clear();
  }

  for(int i = 0; i < N; i++) {
    int b_id = i/BLOCK_SIZE;
    blocks[b_id].append(A[i]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  BLOCK_SIZE = int(sqrt(N));

  for(int i = 0; i < N; i++) cin >> A[i];

  B = (N - 1)/BLOCK_SIZE + 1;
  blocks.resize(B);

  decompose();

  int Q; cin >> Q;
  int lastans = 0;

  while(Q--) {
    int t; cin >> t;

    if(t == 1) {
      int L, R; cin >> L >> R;
      L = (L + lastans - 1) % N; R = (R + lastans - 1) % N;
      if(L > R) swap(L, R);

      if(L == R) continue;

      pair<int, int> erase_loc = find_block(R);
      int x = blocks[erase_loc.first].data[erase_loc.second];
      pair<int, int> add_loc = find_block(L);

      blocks[erase_loc.first].erase(erase_loc.second);
      blocks[add_loc.first].insert(add_loc.second, x);
    }
    else {
      int L, R, K; cin >> L >> R >> K;
      L = (L + lastans - 1) % N; R = (R + lastans - 1) % N; K = (K + lastans - 1) % N + 1;
      if(L > R) swap(L, R);

      int ans = 0;
      int x = 0;
      for(int i = 0; i < B; i++) {
        int y = x + blocks[i].sz() - 1;

        if(x >= L && y <= R) {
          ans += blocks[i].freq[K];
        }
        else if((L >= x && L <= y) || (R >= x && R <= y)) {
          for(int j = 0; j < blocks[i].data.size(); j++) {
            if(j + x >= L && j + x <= R && blocks[i].data[j] == K) ans++;
          }
        }

        x = y + 1;
      }

      lastans = ans;
      cout << ans << endl;
    }
  }
}
