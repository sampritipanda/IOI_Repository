#include <vector>
#include <algorithm>

using namespace std;

class TheTips {
public:

  vector<string> clues;
  vector<double> res;
  vector<bool> was;

  void rec(int i, double probs){
    if(was[i]) return;
    was[i] = true;
    res[i] *= (1 - probs);
    for(int j = 0; j < clues.size(); j++){
      if(clues[i][j] == 'Y') rec(j, probs);
    }
  }

  double solve(vector <string> clues, vector <int> probability) {
    this->clues = clues;
    res.clear();
    res.resize(clues.size(), 1);
    for(int i = 0; i < clues.size(); i++){
      was.clear();
      was.resize(clues.size(), false);

      rec(i, probability[i]/100.0);
    }

    double resD = 0;
    for(auto it: res){
      resD += 1 - it;
    }
    return resD;
  }
};
