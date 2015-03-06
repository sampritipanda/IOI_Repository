// Censoring

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

char S_c[1000001], T_c[1000001];

void calcPrefix(string& S, vector<int>& prefix){
  int M = S.size();
  prefix.push_back(-1);
  int k = -1;
  for(int q = 1; q < M; q++){
    while(k > 1 && S[k + 1] != S[q]){
      k = prefix[k];
    }
    if(S[k + 1] == S[q]){
      k++;
    }
    prefix.push_back(k);
  }
}

int main() {
  // freopen("censor.in", "r", stdin);
  // freopen("censor.out", "w", stdout);

  scanf(" %s", S_c);
  scanf(" %s", T_c);
  string S(S_c);
  string T(T_c);

  vector<int> prefix;
  calcPrefix(T, prefix);
  bool change = true;
  while(change){
    change = false;
    string next = "";
    int x = 0;
    int N = S.size(), M = T.size();
    int q = -1;
    for(int i = 0; i < N; i++){
      while(q > -1 && T[q + 1] != S[i]){
        q = prefix[q];
      }
      if(T[q + 1] == S[i]){
        q++;
      }
      if(q == M - 1){
        change = true;
        int r = i - M + 1;
        if(r) next += S.substr(x, r);
        x = r + T.size();

        q = prefix[q];
      }
    }

    if(x - S.size()){
      next += S.substr(x, S.size() - x);
    }
    S = next;
  }

  printf("%s\n", S.c_str());

  fclose(stdin);
  fclose(stdout);
}
