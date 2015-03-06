// Magic Tricks

#include <stdio.h>
#include <string.h>

char P[1000005];
int prefix[26][1000005];

int main() {
	scanf("%s", P);
	int N = strlen(P);
	for(int i = 0; i < 26; i++) prefix[i][0] = 0;
	prefix[P[0] - 'a'][0]++;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 26; j++) prefix[j][i] = prefix[j][i - 1];
		prefix[P[i] - 'a'][i]++;
	}
	
	int Q; scanf(" %d", &Q);
	while(Q--){
		char c; int L, R;
		scanf(" %c %d %d", &c, &L, &R);
		L--; R--;
		if(L == 0) printf("%d\n", prefix[c - 'a'][R]);
		else printf("%d\n", prefix[c - 'a'][R] - prefix[c - 'a'][L - 1]);
	}
}