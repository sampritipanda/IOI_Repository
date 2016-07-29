#include "grader.h"

#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> C;

void initialize(int n) {
  N = n;
  C.resize(N);
  for(int i = 0; i < N; i++) C[i] = 0;
}

int hasEdge(int u, int v) {
  if(u < v) swap(u, v);

  C[u]++;
  if(C[u] == u) {
    return 1;
  }
  else {
    return 0;
  }
}
