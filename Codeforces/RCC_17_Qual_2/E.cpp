#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

const int BLOCK_SIZE = 300;
const int OFFSET = 1e5;
int A[100001];
int P[100001];
vector<pair<int, int> > queries;
deque<int> indices[200001];
int freq[100301];
int freq_sqr[1001];

bool compare(pair<int, int> A, pair<int, int> B) {
  if(A.first/BLOCK_SIZE == B.first/BLOCK_SIZE) return A.second < B.second;
  return A.first/BLOCK_SIZE < B.first/BLOCK_SIZE;
}

void add(int i) {
  int j = P[i] + OFFSET;

  int prev_ans = -1;
  if(indices[j].size() > 0) prev_ans = indices[j].back() - indices[j].front();
  if(prev_ans != -1) {
    freq[prev_ans]--;
    freq_sqr[prev_ans/BLOCK_SIZE]--;
  }

  if(indices[j].size() == 0 || i > indices[j].back()) {
    indices[j].push_back(i);
  }
  else {
    indices[j].push_front(i);
  }
  int curr_ans = indices[j].back() - indices[j].front();
  freq[curr_ans]++;
  freq_sqr[curr_ans/BLOCK_SIZE]++;
}

void remove(int i) {
  int j = P[i] + OFFSET;

  int prev_ans = indices[j].back() - indices[j].front();
  freq[prev_ans]--;
  freq_sqr[prev_ans/BLOCK_SIZE]--;
  if(indices[j].front() == i) {
    indices[j].pop_front();
  }
  else {
    indices[j].pop_back();
  }

  int curr_ans = -1;
  if(indices[j].size() > 0) curr_ans = indices[j].back() - indices[j].front();
  if(curr_ans != -1) {
    freq[curr_ans]++;
    freq_sqr[curr_ans/BLOCK_SIZE]++;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];

    int Q; cin >> Q;
    queries.resize(Q);
    for(int i = 0; i < Q; i++) {
      cin >> queries[i].first >> queries[i].second;
      queries[i].first--;
    }
    sort(queries.begin(), queries.end(), compare);

    long long ans = 0;
    int L = 0, R = -1;
    for(auto it: queries) {
      int qL = it.first, qR = it.second;
      while(R < qR) {
        add(++R);
      }
      while(R > qR) {
        remove(R--);
      }
      while(L > qL) {
        add(--L);
      }
      while(L < qL) {
        remove(L++);
      }

      int max_block = -1;
      for(int i = 0; i < 400; i++) {
        if(freq_sqr[i]) max_block = max(max_block, i);
      }
      int curr_ans = -1;
      for(int i = max_block * BLOCK_SIZE; i < (max_block + 1) * BLOCK_SIZE; i++) {
        if(freq[i]) curr_ans = max(curr_ans, i);
      }
      ans += curr_ans;
    }

    while(R >= L) remove(R--);

    cout << ans << endl;
  }
}
