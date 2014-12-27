// Transform the Expression

#include <stdio.h>
#include <string.h>
#include <stack>

int main()
{
	int N = 0;
	std::stack<char> operators;
	
	scanf("%d", &N);
	
	while(N--){
		char a[400];
		scanf("%s", a);
		for(int i = 0; i < strlen(a); i++){
			if(a[i] == '(') {
				continue;
			}
			else if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^') {
				operators.push(a[i]);
			}
			else if(a[i] == ')') {
				printf("%c", operators.top());
				operators.pop();
			}
			else {
				printf("%c", a[i]);
			}
		}
		printf("\n");
	}
}