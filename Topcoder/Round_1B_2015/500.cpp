#include <vector>
#include <algorithm>

using namespace std;

class TheTips {
  public:
  double solve(vector <string> clues, vector <int> probability) {
    int N = probability.size();
    double ans[N]; for(int i = 0; i < N; i++) ans[i] = 0.0;
    for(int i = 0; i < N; i++){
      ans[i] += probability[i]/100.0;
      for(int j = 0; j < N; j++){
        if(i == j || clues[i][j] == 'N') continue;

        ans[j] += probability[i]/100.0;
      }
    }
    double total = 0;
    for(int i = 0; i < N; i++){
      total += ans[i];
    }
    return total;
  }
};
