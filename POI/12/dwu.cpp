#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

const int MAX_M = 100000;

int A[50001];
int B[50001];
set<int> I_A[MAX_M + 1];
set<int> I_B[MAX_M + 1];
bool S_A[50001];
bool S_B[50001];

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    I_A[A[i]].insert(i);
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &B[i]);
    I_B[B[i]].insert(i);
  }

  for(int i = 1; i <= MAX_M; i++) {
    if(I_A[i].size() == 2) {
      S_A[*I_A[i].begin()] = S_A[*I_A[i].rbegin()] = true;
    }
    else if(I_B[i].size() == 2) {
      S_B[*I_B[i].begin()] = S_B[*I_B[i].rbegin()] = true;
    }
  }

  int ans = 0;
  for(int i = 1; i <= N; i++) {
    if(S_A[i] && S_B[i]) {
      ans++;
      I_A[A[i]].erase(i);
      I_B[A[i]].insert(i);

      I_B[B[i]].erase(i);
      I_A[B[i]].insert(i);

      S_A[i] = false;
      S_B[i] = false;
      S_A[*I_A[A[i]].begin()] = false;
      S_B[*I_B[B[i]].begin()] = false;
    }
  }

  for(int i = 1; i <= N; i++) {
    if(S_A[i]) {
      if(I_A[B[i]].size() == 0) {
        ans++;

        S_A[i] = false;
        I_A[B[i]].insert(i);
        I_B[B[i]].erase(i);

        I_A[A[i]].erase(i);
        I_B[A[i]].insert(i);
      }
    }
    else if(S_B[i]) {
      if(I_B[A[i]].size() == 0) {
        ans++;

        S_B[i] = false;
        I_A[A[i]].erase(i);
        I_B[A[i]].insert(i);

        I_A[B[i]].insert(i);
        I_B[B[i]].erase(i);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    assert(!S_A[i]);
    assert(!S_B[i]);
  }

  printf("%d\n", ans);
}
