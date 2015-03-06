// Fox And Names

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; cin >> N;
  vector<string> names(N);
  vector<vector<string> > dict(26);

  for(int i = 0; i < N; i++) {
    cin >> names[i];
    dict[names[i][0] - 'a'].push_back(names[i]);
  }

  string permutation = "abcdefghijklmnopqrstuvwxyz";
  bool flag = true;

  for(int i = 1; i < N; i++){
    char a, b;
    int x = 0;
    bool less = true;
    while(x < names[i - 1].length() && x < names[i].length()){
      a = names[i - 1][x];
      b = names[i][x];
      if(permutation.find(a) < permutation.find(b)){
        break;
      }
      else if(permutation.find(a) > permutation.find(b)){
        less = false;
        break;
      }
      x++;
    }

    if(!less) {
      permutation.erase(permutation.find(b), 1);
      permutation.insert(permutation.find(a) + 1, 1, b);
    }
  }

  for(int i = 0; i < 26; i++){
    if(dict[i].size() > 1){
      for(int j = 1; j < dict[i].size(); j++){
        char a, b;
        int x = 0;
        bool less = true;
        while(x < dict[i][j - 1].length() && x < dict[i][j].length()){
          a = dict[i][j - 1][x];
          b = dict[i][j][x];
          if(permutation.find(a) < permutation.find(b)){
            break;
          }
          else if(permutation.find(a) > permutation.find(b)){
            less = false;
            break;
          }
          x++;
        }

        if(!less) {
          permutation.erase(permutation.find(b), 1);
          permutation.insert(permutation.find(a) + 1, 1, b);
        }
      }
    }
  }

  for(int i = 1; i < N; i++){
    int x = 0;
    bool less = true;
    while(x < names[i - 1].length() && x < names[i].length()){
      if(permutation.find(names[i - 1][x]) < permutation.find(names[i][x])){
        break;
      }
      else if(permutation.find(names[i - 1][x]) > permutation.find(names[i][x])){
        less = false;
        break;
      }
      x++;
    }

    if(!less) {
      flag = false;
      break;
    }
  }



  if(flag) cout << permutation << endl;
  else cout << "Impossible" << endl;
}
