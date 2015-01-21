// The Football

#include <iostream>
#include <vector>

using namespace std;

class TheFootballDivTwo {
  public:
  int find(int yourScore, vector <int> scores, vector <int> numberOfTeams) {
    int LEY = 0, LEY3 = 0, LY6 = 0, R = 0;
    int N = scores.size();
    for(int i = 0; i < N; i++){
      if(scores[i] <= yourScore) LEY += numberOfTeams[i];
      else if(scores[i] <= yourScore + 3) LEY3 += numberOfTeams[i];
      else if(scores[i] <= yourScore + 6) LY6 += numberOfTeams[i];
      else R += numberOfTeams[i];
    }

    int V = LEY + LEY3 + LY6 + R + 1;
    V -= 2 * (LEY - R);
    V -= LEY3;

    int ans = R + (V + 1)/2 + 1;
    return ans;
  }
};
