// Rock-Paper-Scissors Tournament

#include <iostream>
#include <string>

using namespace std;

int main() {
  while(true){
    int N; cin >> N;
    if(N == 0) break;
    int K; cin >> K;
    int wins[N + 1], total[N + 1];
    for(int i = 0; i <= N; i++) wins[i] = total[i] = 0;

    for(int i = 0; i < (K * (N*(N - 1))/2); i++){
      int p1, p2; string m1, m2; cin >> p1 >> m1 >> p2 >> m2;
      if(m1 == m2) continue;
      else {
        bool first_win = false;
        if(m1 == "rock" && m2 == "scissors") first_win = true;
        else if(m1 == "paper" && m2 == "rock") first_win = true;
        else if(m1 == "scissors" && m2 == "paper") first_win = true;

        if(first_win) wins[p1]++;
        else wins[p2]++;

        total[p1]++;
        total[p2]++;
      }
    }

    for(int i = 1; i <= N; i++){
      if(total[i] == 0) cout << "-" << endl;
      else printf("%.3f\n", wins[i]/double(total[i]));
    }
    cout << endl;
  }
}
