// Vasya and Football

#include <stdio.h>

int main() {
  char home[21], away[21];
  scanf("%s", home);
  scanf(" %s", away);
  int N; scanf(" %d", &N);

  int home_players[99] = {0}, away_players[99] = {0};
  while(N--){
    int t; char s; int p; char c;
    scanf("%d %c %d %c", &t, &s, &p, &c);
    if(s == 'h'){
      if(c == 'y') home_players[p]++;
      else home_players[p] += 2;

      if(home_players[p] >= 2) {
        printf("%s %d %d\n", home, p, t);
        home_players[p] = -100000;
      }
    }
    else{
      if(c == 'y') away_players[p]++;
      else away_players[p] += 2;

      if(away_players[p] >= 2) {
        printf("%s %d %d\n", away, p, t);
        away_players[p] = -100000;
      }
    }
  }
}
