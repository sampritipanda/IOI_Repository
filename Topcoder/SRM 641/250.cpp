// Buying Tshirts

#include <iostream>
#include <vector>

using namespace std;

class BuyingTshirts {
    public:
    int meet(int T, vector <int> Q, vector <int> P) {
      int N = Q.size();
      int count = 0;
      int q_curr = 0, p_curr = 0;
      for(int i = 0; i < N; i++){
        q_curr += Q[i];
        p_curr += P[i];
        bool q_bought = false, p_bought = false;
        if(q_curr >= T){
          q_curr -= T;
          q_bought = true;
        }
        if(p_curr >= T){
          p_curr -= T;
          p_bought = true;
        }

        if(q_bought && p_bought) count++;
      }

      return count;
    }
};

int main() {
	BuyingTshirts test;
}
