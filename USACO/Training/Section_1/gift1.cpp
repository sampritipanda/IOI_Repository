/*
ID: sampdin1
PROG: gift1
LANG: C++11
*/

#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);

  int NP; scanf("%d", &NP);
  map<string, int> initial_amount;
  map<string, int> final_amount;
  vector<string> people;

  for(int i = 0; i < NP; i++){
    char s[10]; scanf(" %s", s);
    string gifter(s);
    people.push_back(gifter);
    final_amount[gifter] = 0;
  }

  for(int i = 0; i < NP; i++){
    char s[20]; scanf(" %s", s);
    string gifter(s);

    int money, num_gifts; scanf(" %d %d", &money, &num_gifts);
    initial_amount[gifter] = money;

    for(int i = 0; i < num_gifts; i++){
      char p[20]; scanf(" %s", p);
      string giftee(p);

      final_amount[giftee] += money/num_gifts;
    }

    if(num_gifts > 0) final_amount[gifter] += money % num_gifts;
  }

  for(int i = 0; i < NP; i++){
    printf("%s %d\n", people[i].c_str(), final_amount[people[i]] - initial_amount[people[i]]);
  }

  fclose(stdin);
  fclose(stdout);
}
