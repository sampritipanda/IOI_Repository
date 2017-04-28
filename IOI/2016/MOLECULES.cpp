#include "molecules.h"
#include <algorithm>
#include <vector>

using namespace std;

vector<int> find_subset(int L, int R, vector<int> A) {
  int N = A.size();
  vector<pair<int, int> > B(N);
  for(int i = 0; i < N; i++) {
    B[i] = {A[i], i};
  }
  sort(B.begin(), B.end());
  int i = 0, j = -1;
  long long sum = 0;
  while(j < N && sum < L) {
    sum += B[++j].first;
    if(sum >= L) {
      if(sum <= R) break;
      while(sum > R && i <= j) {
        sum -= B[i++].first;
      }
    }
  }
  vector<int> ans;
  if(sum >= L && sum <= R) {
    while(i <= j) {
      ans.push_back(B[i].second);
      i++;
    }
  }
  return ans;
}

