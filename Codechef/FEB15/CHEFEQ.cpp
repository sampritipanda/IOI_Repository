// Chef and Equality

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<int, int> count;
  int T; cin >> T;

  while(T--){
    count.clear();
    int N; cin >> N;
    for(int i = 0; i < N; i++){
      int A; cin >> A;
      count[A]++;
    }

    int maxCount = 0;
    for(auto it: count){
      if(it.second > maxCount) maxCount = it.second;
    }

    cout << N - maxCount << endl;
  }
}
