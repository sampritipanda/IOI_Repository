// Discount on crackers

#include <stdio.h>
#include <string.h>

int main(){
	int P; scanf("%d", &P);
	char S[1001], T[1001];
	int M;
	
	while(P--){
		scanf("%s", S);		
		scanf("%s", T);
		scanf("%d", &M);
		int table[26][26] = {0};
		while(M--){
			char a, b;
			scanf(" %c->%c", &a, &b);
			table[a - 'a'][b - 'a'] = 1;
		}
		
		if(strlen(S) != strlen(T)) printf("NO\n");
    else if(M == 0){
      if(strcmp(S, T) == 0) printf("YES\n");
      else printf("NO\n");
    }
		else {
			int len = strlen(S);
			int flag = true;
			for(int i = 0; i < len; i++){
				if(S[i] != T[i] && table[S[i] - 'a'][T[i] - 'a'] == 0) {
					flag = false;
					break;
				}
			}
			if(flag) printf("YES\n");
			else printf("NO\n");
		}
	}
}
