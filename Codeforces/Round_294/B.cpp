// A and B and Compilation Errors

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int N; cin >> N;
  unordered_multiset<int> errors;
  int orig[N];

  for(int i = 0; i < N; i++){
    int curr; cin >> orig[i];
    errors.insert(orig[i]);
  }

  for(int i = 0; i < (N - 1); i++){
    int curr; cin >> curr;
    errors.erase(errors.find(curr));
  }
  int error = *errors.begin();
  cout << error << endl;
  errors.clear();

  for(int i = 0; i < N; i++) errors.insert(orig[i]);
  errors.erase(errors.find(error));
  for(int i = 0; i < (N - 2); i++){
    int curr; cin >> curr;
    errors.erase(errors.find(curr));
  }
  error = *errors.begin();
  cout << error << endl;
}
