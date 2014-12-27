// Tournament

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int N; scanf("%d", &N);
	long long strength[N];

	for(int i = 0; i < N; i++){
    scanf("%lld", &strength[i]);
	}

  std::sort(strength, strength + N);
	
	long long revenue = 0;
  long long sum = strength[0];
	for(int i = 1; i < N; i++){
    revenue += strength[i] * i - sum;
    sum += strength[i];
	}
	
  printf("%lld\n", revenue);
	
	return 0;
}
