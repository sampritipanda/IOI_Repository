// Bessie Goes Moo

#include <stdio.h>
#include <vector>

using namespace std;

inline int abs(int a){
  return (a < 0 ? -a : a);
}

int main() {
  freopen("bgm.in", "r", stdin);
  freopen("bgm.out", "w", stdout);

  // B = 0, E = 1, S = 2, I = 3, G = 4, O = 5, M = 6
  // (B + 2*E + 2*S + I) (G + O + E + S) (M + 2*O)
  vector<int> values[7];

  int N; scanf("%d", &N);
  while(N--){
    char type; int val; scanf(" %c %d", &type, &val);
    if(type == 'B') values[0].push_back(val);
    else if(type == 'E') values[1].push_back(val);
    else if(type == 'S') values[2].push_back(val);
    else if(type == 'I') values[3].push_back(val);
    else if(type == 'G') values[4].push_back(val);
    else if(type == 'O') values[5].push_back(val);
    else if(type == 'M') values[6].push_back(val);
  }

  long long ways = 0;
  for(auto B: values[0]){
    for(auto E: values[1]){
      for(auto S: values[2]){
        for(auto I: values[3]){
          for(auto G: values[4]){
            for(auto O: values[5]){
              for(auto M: values[6]){
                if(abs(B + 2*E + 2*S + I) % 7 == 0) ways++;
                else if(abs(G + O + E + S) % 7 == 0) ways++;
                else if(abs(M + 2*O) % 7 == 0) ways++;
              }
            }
          }
        }
      }
    }
  }

  printf("%lld\n", ways);

  fclose(stdin);
  fclose(stdout);
}
