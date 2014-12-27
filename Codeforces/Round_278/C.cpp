// Fight the Monster

#include <iostream>

using namespace std;

inline int max(int a, int b){
  return (a > b ? a : b);
}

int main(){
  int stats_Y[3], stats_M[3], price[3];
  cin >> stats_Y[0] >> stats_Y[1] >> stats_Y[2];
  cin >> stats_M[0] >> stats_M[1] >> stats_M[2];
  cin >> price[0] >> price[1] >> price[2];

  int m_decrease = max(0, stats_Y[1] - stats_M[2]);
  int y_decrease = max(0, stats_M[1] - stats_Y[2]);

  int steps_to_monster_death = 0;
  if(stats_M[0] % m_decrease == 0) steps_to_monster_death = stats_M[0]/m_decrease;
  else steps_to_monster_death = stats_M[0]/m_decrease + 1;

  int diff = stats_Y[0] - steps_to_monster_death*y_decrease;
  if(diff > 0) {
    cout << 0 << endl;
  }
  else {
    int hp_req = 1 - diff;
    int price_hp = price[1] * hp_req;
  }
}
