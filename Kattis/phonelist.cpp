// Phone List

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    int N; cin >> N;
    vector<string> numbers;
    for(int i = 0; i < N; i++){
      string s; cin >> s;
      numbers.push_back(s);
    }

    sort(numbers.begin(), numbers.end());

    bool flag = true;
    for(int i = 1; i < N; i++){
      if(numbers[i - 1] == numbers[i].substr(0, numbers[i - 1].length())){
        flag = false;
        break;
      }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
