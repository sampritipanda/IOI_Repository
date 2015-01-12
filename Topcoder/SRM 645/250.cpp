// Bacteria Colony

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BacteriesColony {
  public:
  vector <int> performTheExperiment(vector <int> colonies) {
    int N = colonies.size();
    while(true){
      vector<int> colonies_new = colonies;
      bool changed = false;
      for(int i = 1; i <= N - 2; i++){
        if(colonies[i - 1] > colonies[i] && colonies[i + 1] > colonies[i]){
          colonies_new[i]++;
          changed = true;
        }
        else if(colonies[i - 1] < colonies[i] && colonies[i + 1] < colonies[i]){
          colonies_new[i]--;
          changed = true;
        }
      }

      colonies = colonies_new;
      if(!changed) break;
    }

    return colonies;
  }
};

int main() {
  BacteriesColony test;
  vector<int> result1 = test.performTheExperiment({5, 3, 4, 6, 1 });
  vector<int> result2 = test.performTheExperiment({1, 5, 4, 9 });
  vector<int> result3 = test.performTheExperiment({78, 34, 3, 54, 44, 99 });
  vector<int> result4 = test.performTheExperiment({32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 });

  for(auto it: result1) cout << it << " ";
  cout << endl;
  for(auto it: result2) cout << it << " ";
  cout << endl;
  for(auto it: result3) cout << it << " ";
  cout << endl;
  for(auto it: result4) cout << it << " ";
  cout << endl;
}

