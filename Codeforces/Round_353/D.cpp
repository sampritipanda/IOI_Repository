#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ans[100001];
int A[100001];
bool left[100001];
bool right[100001];
map<int, int> compres;
int R_map[100001];
set<int> vals;

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) scanf("%d", &A[i]);
  int timer = 0;
  for(int i = 0; i < N; i++) {
    compres[A[i]] = 0;
  }
  for(auto it: compres) {
    compres[it.first] = ++timer;
    R_map[timer] = it.first;
  }
  for(int i = 0; i < N; i++) A[i] = compres[A[i]];

  ans[A[0]] = 0;
  vals.insert(A[0]);

  for(int i = 1; i < N; i++) {
    auto it = vals.upper_bound(A[i]);
    if(it == vals.end()) {
      int add = *vals.rbegin();
      ans[A[i]] = add;
      right[add] = true;
    }
    else if(it == vals.begin()) {
      int add = *vals.begin();
      ans[A[i]] = add;
      left[add] = true;
    }
    else {
      int add = *it;
      if(left[add]) {
        advance(it, -1); add = *it;
        ans[A[i]] = add;
        right[add] = true;
      }
      else {
        ans[A[i]] = add;
        left[add] = true;
      }
    }
    vals.insert(A[i]);
  }

  for(int i = 1; i < N; i++) printf("%d ", R_map[ans[A[i]]]); printf("\n");
}

