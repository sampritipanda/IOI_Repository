// Voting

#include <stdio.h>
#include <map>

int main(){
	int N1, N2, N3, N4, N5;
	scanf("%d %d %d %d %d", &N1, &N2, &N3, &N4, &N5);
	int candidate;
  std::map<int, int> candidates;
	
	while(N1--){
		scanf("%d", &candidate);
    candidates[candidate]++;
	}
	while(N2--){
		scanf("%d", &candidate);
    candidates[candidate]++;
	}
	while(N3--){
		scanf("%d", &candidate);
    candidates[candidate]++;
	}
	while(N4--){
		scanf("%d", &candidate);
    candidates[candidate]++;
	}
	while(N5--){
		scanf("%d", &candidate);
    candidates[candidate]++;
	}

  int count = 0;
  for (std::map<int,int>::iterator it=candidates.begin(); it!=candidates.end(); ++it){
    if(it->second >= 3) count++;
  }
	printf("%d\n", count);
}
