// Array and Operations

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}

bool sort_compare(pair<pair<int, int>, int > a, pair<pair<int, int>, int > b){
	return a.second < b.second;
}

int main() {
  int N, M; scanf("%d %d", &N, &M);
  int A[N + 1]; vector<pair<pair<int, int>, int > > good;
  
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  
  for(int i = 0; i < M; i++){
	int l, r;
	scanf("%d %d", &l, &r);
	good.push_back(make_pair(make_pair(l, r), gcd(A[l], A[r])));
  }
  
  sort(good.begin(), good.end(), sort_compare);
  
  int operations = 0;
  for(int i = 0; i < M; i++){
	int l = good[i].first.first, r = good[i].first.second;
	int divisor = gcd(A[l], A[r]);
	while(divisor != 1){
		for(int i = 2; i <= divisor; i++){
			if(divisor % i == 0){
				divisor /= i;
				A[l] /= i;
				A[r] /= i;
				operations++;
				break;
			}
		}
	}
  }
  
  printf("%d\n", operations);
}
