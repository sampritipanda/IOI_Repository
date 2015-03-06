// Kitayuta Mart

#include <cmath>

using namespace std;

class KitayutaMart2 {
  public:
  int numBought(int K, int T) {
    T /= K;
    T++;
    int num = log2(T);
    return num;
  }
};

