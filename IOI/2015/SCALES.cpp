#include "scales.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

const int HEIGHT = 6;
vector<int> perms[720];
vector<vector<int> > ops;
int precalc[720][120];
int optima[HEIGHT + 1];
int best[HEIGHT][720];

int _getHeaviest(vector<int>& arr, int A, int B, int C) {
  vector<int> arr2 = {arr[A], arr[B], arr[C]};
  sort(arr2.begin(), arr2.end());
  int ans = arr2[2];
  if(ans == arr[A]) return A;
  else if(ans == arr[B]) return B;
  return C;
}

int _getLightest(vector<int>& arr, int A, int B, int C) {
  vector<int> arr2 = {arr[A], arr[B], arr[C]};
  sort(arr2.begin(), arr2.end());
  int ans = arr2[0];
  if(ans == arr[A]) return A;
  else if(ans == arr[B]) return B;
  return C;
}

int _getMedian(vector<int>& arr, int A, int B, int C) {
  vector<int> arr2 = {arr[A], arr[B], arr[C]};
  sort(arr2.begin(), arr2.end());
  int ans = arr2[1];
  if(ans == arr[A]) return A;
  else if(ans == arr[B]) return B;
  return C;
}

int _getNextLightest(vector<int>& arr, int A, int B, int C, int D) {
  vector<int> arr2;
  if(arr[A] > arr[D]) arr2.push_back(arr[A]);
  if(arr[B] > arr[D]) arr2.push_back(arr[B]);
  if(arr[C] > arr[D]) arr2.push_back(arr[C]);
  if(arr2.empty()) arr2 = {arr[A], arr[B], arr[C]};
  sort(arr2.begin(), arr2.end());
  int ans = arr2[0];
  if(ans == arr[A]) return A;
  else if(ans == arr[B]) return B;
  return C;
}

int call(int type, int A, int B, int C, int D = 0) {
  A++; B++; C++; D++;
  if(type == 0) {
    return getHeaviest(A, B, C) - 1;
  }
  else if(type == 1) {
    return getLightest(A, B, C) - 1;
  }
  else if(type == 2) {
    return getMedian(A, B, C) - 1;
  }
  else {
    return getNextLightest(A, B, C, D) - 1;
  }
}

bool build(int layer, vector<int>& cands) {
  if(layer == HEIGHT) return true;

  for(int j = 0; j < ops.size(); j++) {
    vector<int> split[6];
    for(int i: cands) {
      split[precalc[i][j]].push_back(i);
    }

    bool pos = true;
    for(int k = 0; k < 6; k++) {
      if(split[k].size() > optima[layer + 1]) pos = false;
    }
    if(!pos) continue;

    for(int k = 0; k < 6; k++) {
      if(split[k].size() == 0) continue;
      pos &= build(layer + 1, split[k]);
      if(!pos) break;
    }
    if(pos) {
      best[layer][cands[0]] = j;
      return true;
    }
  }

  return false;
}

void init(int T) {
  perms[0] = {1, 2, 3, 4, 5, 6};
  for(int i = 1; i < 720; i++) {
    perms[i] = perms[i - 1];
    next_permutation(perms[i].begin(), perms[i].end());
  }

  for(int i = 0; i < 720; i++) {
    ops.clear();
    for(int j = 0; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        for(int l = k + 1; l < 6; l++) {
          precalc[i][ops.size()] = _getHeaviest(perms[i], j, k, l);
          ops.push_back({0, j, k, l});
        }
      }
    }

    for(int j = 0; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        for(int l = k + 1; l < 6; l++) {
          precalc[i][ops.size()] = _getLightest(perms[i], j, k, l);
          ops.push_back({1, j, k, l});
        }
      }
    }

    for(int j = 0; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        for(int l = k + 1; l < 6; l++) {
          precalc[i][ops.size()] = _getMedian(perms[i], j, k, l);
          ops.push_back({2, j, k, l});
        }
      }
    }

    for(int j = 0; j < 6; j++) {
      for(int k = j + 1; k < 6; k++) {
        for(int l = k + 1; l < 6; l++) {
          for(int m = 0; m < 6; m++) {
            if(m == j || m == k || m == l) continue;
            precalc[i][ops.size()] = _getNextLightest(perms[i], j, k, l, m);
            ops.push_back({3, j, k, l, m});
          }
        }
      }
    }
  }

  optima[HEIGHT] = 1;
  for(int i = HEIGHT - 1; i >= 0; i--) {
    optima[i] = optima[i + 1] * 3;
  }

  vector<int> cands;
  for(int i = 0; i < 720; i++) cands.push_back(i);
  assert(build(0, cands));
}

int solve(int layer, vector<int> cands) {
  if(layer == HEIGHT) return cands[0];

  int curr = best[layer][cands[0]];
  int res = call(ops[curr][0], ops[curr][1], ops[curr][2], ops[curr][3], ops[curr][4]);

  vector<int> nxt;
  for(int i: cands) {
    if(precalc[i][curr] == res) nxt.push_back(i);
  }
  return solve(layer + 1, nxt);
}

void orderCoins() {
  vector<int> cands;
  for(int i = 0; i < 720; i++) cands.push_back(i);
  int id = solve(0, cands);
  int *ans = new int[6];
  for(int i = 0; i < 6; i++) {
    ans[perms[id][i] - 1] = i + 1;
  }
  answer(ans);
}
