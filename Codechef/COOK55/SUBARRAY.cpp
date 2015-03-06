// Parenthesis with Maximum Sum Subarray 

#include <stdio.h>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int first[N]; char second[N];
    for(int i = 0; i < N; i++) scanf(" %c", &second[i]);
    for(int i = 0; i < N; i++) scanf(" %d", &first[i]);

    long long max_so_far = 0, max_ending_here = 0;
    long long curr_balancing_1 = 0, curr_balancing_2 = 0, curr_balancing_3 = 0, curr_balancing_4 = 0;
    for(int i = 0; i < N; i++){
      if(second[i] == '(') curr_balancing_1++;
      if(second[i] == '<') curr_balancing_2++;
      if(second[i] == '{') curr_balancing_3++;
      if(second[i] == '[') curr_balancing_4++;
      if(second[i] == ')') curr_balancing_1--;
      if(second[i] == '>') curr_balancing_2--;
      if(second[i] == '}') curr_balancing_3--;
      if(second[i] == ']') curr_balancing_4--;


      max_ending_here += first[i];
      if(max_ending_here < 0 || curr_balancing_1 < 0 || curr_balancing_2 < 0 || curr_balancing_3 < 0 || curr_balancing_4 < 0) {
        max_ending_here = 0;
        curr_balancing_1 = curr_balancing_2 = curr_balancing_3 = curr_balancing_4 = 0;
      }
      if(max_ending_here > max_so_far && curr_balancing_1 == 0 && curr_balancing_2 == 0 && curr_balancing_3 == 0 && curr_balancing_4 == 0) max_so_far = max_ending_here;
    }

    for(int i = 0; i < N - 1; i++){
      char a = second[i], b = second[i + 1];
      if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '<' && b == '>')){
        if((first[i] + first[i + 1]) > max_so_far) max_so_far = first[i] + first[i + 1];
      }
    }

    printf("%lld\n", max_so_far);
  }
}
