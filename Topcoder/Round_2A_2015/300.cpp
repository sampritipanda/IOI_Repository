#include <vector>
#include <algorithm>

using namespace std;

class ModModMod {
  public:
    long long findSum(vector<int> v , int r){
      int n = v.size();
      int pos[n];
      for(int i = 0 ; i < n ; ++i){
        pos[i] = n;
        for(int j = i + 1 ; j < n ; ++j){
          if(v[j] < v[i]){
            pos[i] = j;
            break;
          }
        }
      }
      long long answer = 0;
      for(int i = 1 ; i <= r ; ++i){
        int cur = i;
        for(int j = 0 ; j < n ; j = pos[j]){
          cur %= v[j];
          if(!cur){
            break;
          }
        }
        answer += cur;
      }
      return answer;
    }
};

