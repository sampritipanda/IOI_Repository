// Cooking the Books

#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  for(int i = 1; i <= T; i++){
    string N; cin >> N;
    int len = N.length();
    int max_num = stoi(N), min_num = stoi(N);

    if(len == 1){
      max_num = stoi(N);
      min_num = stoi(N);
    }
    else {
      for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
          string temp_N = N;
          if(i == 0 && temp_N[j] == '0') continue;
          else {
            char t = temp_N[j];
            temp_N[j] = temp_N[i];
            temp_N[i] = t;

            int curr_N = stoi(temp_N);
            if(curr_N > max_num) max_num = curr_N;
            if(curr_N < min_num) min_num = curr_N;
          }
        }
      }
    }

    cout << "Case #" << i << ": " << min_num << " " << max_num << endl;
  }
}
