//You are free to include standard headers here
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool query(const bool *); //Do not change this line

const int max_N = 25000;  //Do not change this line
bool q[max_N];            //Do not change this line

//You are free to add variables and functions at global scope here

bool *glob_ans;
int glob_N;
int query_count;

// Returns if L..R contains undiscovered element
bool range_check(int L, int R) {
  query_count++;

  for(int i = 0; i < glob_N; i++) q[i] = true;
  for(int i = L; i <= R; i++) q[i] = false || glob_ans[i];

  return !query(q);
}

void recur(int L, int R) {
  if(L == R) {
    glob_ans[L] = true;
    return;
  }

  int mid = (L + R)/2;
  if(range_check(L, mid)) recur(L, mid);
  else recur(mid + 1, R);
}

//Do not change the following function signature

void solve(int N, bool *ans) {
  glob_N = N;
  glob_ans = ans;

  int BLOCK_SIZE = 500;//int(sqrt(glob_N));
  int i = 0;
  while(i < N) {
    int L = i, R = min(N - 1, i + BLOCK_SIZE - 1);
    while(range_check(L, R)) {
      recur(L, R);
    }
    i += BLOCK_SIZE;
  }

  // cout << endl << query_count << endl;
}
