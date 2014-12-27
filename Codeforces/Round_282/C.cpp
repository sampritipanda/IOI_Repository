// Treasure

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.length();
  vector<int> answers;

  int currDepth = 0;
  bool flag = true;
  for(int i = 0; i < N; i++){
    if(s[i] == '(') currDepth++;
    else if(s[i] == ')') currDepth--;

    if(currDepth < 0){
      flag = false;
      break;
    }
  }

  if(flag){
    currDepth = 0;
    int i = 0;
    while(i < N){
      int j = i + 1;
      if(s[i] == '(') currDepth++;
      else if(s[i] == ')') currDepth--;
      else {
        int numClosers = 0;
        while(j < N){
          if(s[j] == ')') {
            numClosers++;
            j++;
          }
          else break;
        }
        int count = currDepth - numClosers;
        if(count == 0) {
          flag = false;
          break;
        }
        else {
          answers.push_back(count);
          currDepth = 0;
        }
      }
      i = j;
    }
    if(currDepth != 0) flag = false;
  }

  if(flag){
    for(vector<int>::iterator it = answers.begin(); it != answers.end(); ++it) {
      cout << *it << '\n';
    }
  }
  else {
    cout << "-1\n";
  }
}
