// Representative Selection

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; scanf(" %d", &T);

  while(T--){
    int N; scanf(" %d", &N);
    vector<string> strings(N);
    for(int i = 0; i < N; i++){
      char s_c[110]; scanf(" %s", s_c);
      strings[i] = string(s_c);
    }
    char check_c[110]; scanf(" %s", check_c);
    if(binary_search(strings.begin(), strings.end(), string(check_c))) printf("yes\n");
    else printf("no\n");
  }
}
