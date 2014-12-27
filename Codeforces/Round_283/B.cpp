// Secret Combination

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
  int n; scanf("%d", &n);
  int digits[n];

  int minDigit = 9;
  for(int i = 0; i < n; i++){
    char a; scanf(" %c", &a);
    digits[i] = a - '0';
    if(digits[i] < minDigit) minDigit = digits[i];
  }

  vector<int> zeroes;
  for(int i = 0; i < n; i++){
    digits[i] = (digits[i] + (10 - minDigit)) % 10;
    if(digits[i] == 0) zeroes.push_back(i);
  }

  string finalNum ("99999999999");
  bool first = true;
  for(int i = 0; i < n; i++){
    string digitsStr;
    for(int k = i; k < n; k++){
      digitsStr += '0' + digits[k];
    }
    for(int k = 0; k < i; k++){
      digitsStr += '0' + digits[k];
    }
    if(first) {
      finalNum = digitsStr;
      first = false;
    }
    else{
      if(lexicographical_compare(digitsStr.begin(), digitsStr.end(), finalNum.begin(), finalNum.end())){
        finalNum = digitsStr;
      }
    }
  }

  cout << finalNum << endl;
}
