#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[1000001], B[1000001];
vector<pair<int, int> > temp_sort;
int S[1000001];  // left most point for i

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;

  for(int i = 1; i <= K; i++) cin >> A[i] >> B[i];

  for(int i = 1; i <= K; i++) {
    if(A[i] <= B[i]) temp_sort.push_back({B[i], A[i]});
  }
  sort(temp_sort.begin(), temp_sort.end());

  int M = temp_sort.size();

  for(int i = 1; i <= N; i++) S[i] = -1;

  int j = 0;
  for(int i = 1; i <= N; i++) {
    while(j < M && temp_sort[j].first < i) j++;
    if(j == M) break;
  }
}
