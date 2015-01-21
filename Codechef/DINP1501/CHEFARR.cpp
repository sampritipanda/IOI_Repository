// Chef and array

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long range_sum(long long sum[], int i, int j){
  if(i == 0) return sum[j];
  else return sum[j] - sum[i - 1];
}

int main() {
  int N; scanf("%d", &N);

  long long A[N], sum[N];

  for(int i = 0; i < N; i++) scanf("%lld", &A[i]);
  sum[0] = A[0];
  for(int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i];

  if(sum[N - 1] % 3 != 0 || N < 3) printf("0\n");
  else if(N == 3){
    if(A[0] == A[1] && A[1] == A[2]) printf("1\n");
    else printf("0\n");
  }
  else {
    long long each_sum = sum[N - 1]/3;
    vector<int> start_indexes, end_indexes;

    for(int i = 0; i < N - 2; i++) {
      if(range_sum(sum, 0, i) == each_sum) start_indexes.push_back(i);
    }

    for(int i = 2; i < N; i++) {
      if(range_sum(sum, i, N - 1) == each_sum) end_indexes.push_back(i);
    }

    unsigned long long count = 0;
    for(auto it: start_indexes){
      count += end_indexes.size() - (lower_bound(end_indexes.begin(), end_indexes.end(), it + 2) - end_indexes.begin());
    }

    printf("%lld\n", count);
  }
}
