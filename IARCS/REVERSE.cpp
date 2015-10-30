// Reverse

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

vector<vector<string> > A;

int main() {
  int N; cin >> N;
  getchar();
  A.resize(N);

  for(int i = 0; i < N; i++) {
    string S; getline(cin, S);
    istringstream iss(S);
    while(!iss.eof()) {
      string word; iss >> word;
      string word2 = "";
      for(int j = 0; j < word.length(); j++) {
        if(isalpha(word[j])) word2 += word[j];
      }
      if(word2.length() > 0) A[i].push_back(word2);
    }

    reverse(A[i].begin(), A[i].end());
  }

  reverse(A.begin(), A.end());

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < A[i].size(); j++) {
      cout << A[i][j];
      if(j < A[i].size() - 1) cout << " ";
    }
    cout << endl;
  }
}
