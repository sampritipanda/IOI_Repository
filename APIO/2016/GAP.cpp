#include "gap.h"

#include <climits>
#include <vector>
#include <cassert>

using namespace std;

long long findGap(int T, int N) {
  long long L, R;
  MinMax(0, LLONG_MAX, &L, &R);

  if(T == 1) {
    vector<long long> A, B;
    A.push_back(L); B.push_back(R);
    while(L < R && (A.size() + B.size() < N)) {
      long long qL, qR;
      MinMax(L + 1, R - 1, &qL, &qR);
      if(qL == -1) break;
      A.push_back(qL);
      if(qL != qR) B.push_back(qR);
      L = qL, R = qR;
    }
    A.insert(A.end(), B.rbegin(), B.rend());
    long long ans = 0;
    for(int i = 1; i < N; i++) {
      ans = max(ans, A[i] - A[i - 1]);
    }
    return ans;
  }

  long long diff = ((R - L - 1) + (N - 2))/(N - 1);

  vector<pair<long long, long long> > cands;
  cands.push_back({L, L});
  for(long long x = L + 1; x <= R - 1; x += diff) {
    long long qL, qR;
    MinMax(x, min(x + diff - 1, R - 1), &qL, &qR);
    if(qL != -1) cands.push_back({qL, qR});
  }
  cands.push_back({R, R});

  long long ans = 0;
  for(int i = 1; i < cands.size(); i++) {
    ans = max(ans, cands[i].first - cands[i - 1].second);
  }
  return ans;
}
