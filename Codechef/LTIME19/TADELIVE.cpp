// Delivery Man

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sort_compare(pair<int, int> a, pair<int, int> b){
  if(a.first > b.first) return true;
  else if(a.first < b.first) return false;
  else return a.second < b.second;
}

int main() {
  int N, X, Y; scanf("%d %d %d", &N, &X, &Y);
  int A[N], B[N];
  vector<pair<int, int> > tips;

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
    tips.push_back(make_pair(abs(A[i] - B[i]), i));
  }

  sort(tips.begin(), tips.end(), sort_compare);

  long long total_tips = 0;
  for(int j = 0; j < N; j++){
    int i = tips[j].second;
    if(X == 0){
      total_tips += B[i];
      Y--;
    }
    else if(Y == 0){
      total_tips += A[i];
      X--;
    }
    else {
      if(A[i] >= B[i]){
        total_tips += A[i];
        X--;
      }
      else {
        total_tips += B[i];
        Y--;
      }
    }
  }

  printf("%lld\n", total_tips);
}
