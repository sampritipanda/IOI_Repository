// Queue at the School

#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, t; cin >> n >> t;
  string queue; cin >> queue;

  for(int i = 0; i < t; i++){
    int j = 1;
    while(j < n){
      if(queue[j] == 'G' && queue[j - 1] == 'B'){
        queue[j] = 'B';
        queue[j - 1] = 'G';
        j += 2;
      }
      else {
        j++;
      }
    }
  }

  cout << queue << endl;
}
