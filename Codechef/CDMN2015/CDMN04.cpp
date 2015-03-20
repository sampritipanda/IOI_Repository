// Malcolm and Cards

#include <iostream>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;
  map<unsigned long long, int> freq;

  while(T--){
    freq.clear();
    int N; cin >> N;

    for(int i = 0; i < N; i++){
      unsigned long long a; cin >> a;
      freq[a]++;
    }

    unsigned long long product = 1;
    for(auto it: freq){
      product *= (it.second + 1);
    }

    cout << product << endl;
  }
}
