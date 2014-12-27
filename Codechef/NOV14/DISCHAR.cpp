// Distinct Characters Subsequence

#include <stdio.h>
#include <string.h>
#include <set>

int main(){
	int T; scanf("%d", &T);
	char str[100000];
  std::set<char> charset;

	while(T--){
		scanf("%s", str);
		int N = strlen(str);
    for(int i =  0; i < N; i++){
      charset.insert(str[i]);
    }
    printf("%lu\n", charset.size());
    charset.clear();
	}
}
