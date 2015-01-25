// Many bananas

#include <iostream>
#include <set>

using namespace std;

int main() {
  int N; cin >> N;
  set<int> family_types;
  long long family_count[100001] = {0};

  for(int i = 0; i < N; i++){
    int A, B; cin >> A >> B;
    family_types.insert(A);
    family_count[A] = B;
  }

  int M; cin >> M;
  while(M--){
    char type;
    int val;
    cin >> type >> val;

    if(type == '+'){
      if(family_count[val] == 0) family_types.insert(val);
      family_count[val]++;
    }
    else if(type == '-'){
      family_count[val]--;
      if(family_count[val] == 0){
        family_types.erase(val);
      }
    }
    else {
      long long ans = 0;
      for(auto it: family_types){
        ans += (val % it) * family_count[it];
      }
      cout << ans << endl;
    }
  }
}
