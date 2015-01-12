// Janusz In The Casino

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class JanuszInTheCasino {
  public:
  double findProbability(long long n, int m, int k){
    if(n == 1){
      return pow(((m - 1)/double(m)), k);
    }
  }
};

