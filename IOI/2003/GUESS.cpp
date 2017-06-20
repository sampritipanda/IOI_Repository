#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <unordered_map>

using namespace std;

int HEIGHT;
int A[50][8];
bool precalc[50][8][1 << 3];
int optima[10 + 1];
pair<int, int> best[10][50];
int N, P;
unordered_map<long long, pair<int, int> > memo[10];

long long encode(vector<int>& A) {
  long long hash = 0;
  for(int i: A) {
    hash |= (1LL << i);
  }
  return hash;
}

void remap(int layer, vector<int>& cands) {
  if(cands.size() <= 1 || layer == HEIGHT) return;

  pair<int, int> curr = memo[layer][encode(cands)];

  best[layer][cands[0]] = curr;
  vector<int> split[2];
  for(int i: cands) {
    split[precalc[i][curr.first][curr.second]].push_back(i);
  }

  remap(layer + 1, split[0]);
  remap(layer + 1, split[1]);
}

bool build(int layer, vector<int>& cands) {
  if(cands.size() == 1 || layer == HEIGHT) return true;
  long long hash = encode(cands);
  auto it = memo[layer].find(hash);
  if(it != memo[layer].end()) {
    if(it->second.first == -1) return false;
    remap(layer, cands);
    return true;
  }

  for(int j = 0; j < 8; j++) {
    for(int k = 0; k < (1 << 3); k++) {
      vector<int> split[2];
      for(int i: cands) {
        split[precalc[i][j][k]].push_back(i);
      }
      if(split[0].empty() || split[1].empty()) continue;
      if(split[0].size() > optima[layer + 1] || split[1].size() > optima[layer + 1]) continue;

      bool pos = true;
      for(int i = 0; i < 2; i++) {
        pos &= build(layer + 1, split[i]);
        if(!pos) break;
      }
      if(pos) {
        best[layer][cands[0]] = {j, k};
        memo[layer][hash] = {j, k};
        return true;
      }
    }
  }

  memo[layer][hash] = {-1, -1};
  return false;
}

int test(int i, int j) {
  cout << "Q" << " " << (i + 1);
  if(j & (1 << 0)) cout << " X";
  if(j & (1 << 1)) cout << " Y";
  if(j & (1 << 2)) cout << " Z";
  cout << endl;

  int ans; cin >> ans;
  return ans;
}

int solve(int layer, vector<int> cands) {
  if(cands.size() == 1 || layer == HEIGHT) return cands[0];

  pair<int, int> curr = best[layer][cands[0]];
  int res = test(curr.first, curr.second);

  vector<int> nxt;
  for(int i: cands) {
    if(precalc[i][curr.first][curr.second] == res) nxt.push_back(i);
  }
  return solve(layer + 1, nxt);
}

int main() {
  cin >> N >> P;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < P; j++) {
      char c; cin >> c;
      A[i][j] = c - 'X';
    }
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < P; j++) {
      for(int k = 0; k < (1 << 3); k++) {
        precalc[i][j][k] = k & (1 << A[i][j]);
      }
    }
  }

  vector<int> cands;
  for(int i = 0; i < N; i++) cands.push_back(i);

  for(HEIGHT = 1; HEIGHT <= 10; HEIGHT++) {
    // cerr << HEIGHT << endl;
    memset(optima, 0, sizeof optima);
    memset(best, 0, sizeof best);
    for(int i = 0; i < 10; i++) memo[i].clear();

    optima[HEIGHT] = 1;
    for(int i = HEIGHT - 1; i >= 0; i--) {
      optima[i] = optima[i + 1] * 2;
    }

    if(build(0, cands)) break;
  }

  // return 0;

  cout << "C " << (solve(0, cands) + 1) << endl;
}
