// The name list

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main() {
  int t; scanf("%d", &t);
  map<string, int> names;

  while(t--){
    char s[50]; scanf("%s", s);
    string str(s);
    names[s]++;
  }

  for(auto it: names) printf("%s %d\n", it.first.c_str(), it.second);
}
