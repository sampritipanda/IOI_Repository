// Censoring

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

char S_c[1000001], T_c[1000001];

int main() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  scanf(" %s", S_c);
  scanf(" %s", T_c);
  string S(S_c);
  string T(T_c);

  auto it = S.find(T);
  while(it != string::npos){
    S.erase(it, T.size());
    it = S.find(T);
  }

  printf("%s\n", S.c_str());

  fclose(stdin);
  fclose(stdout);
}
