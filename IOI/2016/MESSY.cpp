#include "messy.h"

#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int N;

void add_strings(int L, int R, string base) {
  if(L == R) return;
  int mid = (L + R)/2;
  for(int i = L; i <= mid; i++) {
    base[i] = '1';
    add_element(base);
    base[i] = '0';
  }

  base = string(N, '0');
  string left = base, right = base;
  for(int i = mid + 1; i <= R; i++) left[i] = '1';
  for(int i = L; i <= mid; i++) right[i] = '1';
  add_strings(L, mid, left);
  add_strings(mid + 1, R, right);
}

vector<int> ans_rev;

void solve(int L, int R, vector<int> A, vector<int> other) {
  if(L == R) {
    assert(A.size() == 1);
    ans_rev[L] = A[0];
    return;
  }

  string convert(N, '0');
  for(int i: other) convert[i] = '1';

  vector<int> left, right;
  for(int i: A) {
    convert[i] = '1';
    if(check_element(convert)) left.push_back(i);
    else right.push_back(i);
    convert[i] = '0';
  }

  int mid = (L + R)/2;
  solve(L, mid, left, right);
  solve(mid + 1, R, right, left);
}

std::vector<int> restore_permutation(int n, int w, int r) {
  N = n;
  add_strings(0, N - 1, string(N, '0'));

  compile_set();

  ans_rev.resize(N, -1);
  vector<int> A;
  for(int i = 0; i < N; i++) A.push_back(i);
  solve(0, N - 1, A, {});

  vector<int> ans(N);
  for(int i = 0; i < N; i++) ans[ans_rev[i]] = i;
  return ans;
}
