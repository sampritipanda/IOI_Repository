// Brackets

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

int main(){
  int T; scanf("%d", &T);
  std::string str;

  while(T--){
    int maxBalance = 0, balance = 0;
    std::cin >> str;
    int N = str.length();

    for(int i = 0; i < N; i++){
      if(str[i] == '(') balance++;
      if(str[i] == ')') balance--;
      if(balance > maxBalance) maxBalance = balance;
    }

    for(int i = 0; i < maxBalance; i++) printf("(");
    for(int i = 0; i < maxBalance; i++) printf(")");

    printf("\n");
  }
}
