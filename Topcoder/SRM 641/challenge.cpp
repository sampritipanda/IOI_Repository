// Shuffling Cards

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ShufflingCardsDiv2 {
    public:

    bool a(int x, int N){
      return 1 <= x && x <= N / 2;
    }

    bool b(int x, int N){
      return N / 2 < x  && x <= N;
    }

    string shuffle(vector <int> A) {
      int N = int(A.size()), res = 1;
      for(int i = 0; i < N / 2; i+= 2){
        if(!(a(A[i], N) && b(A[i + 1], N))){
          res = 0;
          break;
        }
      }
      return !res ? "Possible" : "Impossible";
    }
};

int main() {
  ShufflingCardsDiv2 test;
  int size_arr[] = {2, 1};
  std::vector<int> size (size_arr, size_arr + sizeof(size_arr) / sizeof(int) );

  cout << test.shuffle(size) << endl;
}
