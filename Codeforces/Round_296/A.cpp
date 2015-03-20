// Playing with Paper

#include <iostream>

using namespace std;

int main() {
  long long a, b; cin >> a >> b;
  long long count = 0;
  while(a != 0 && b != 0){
    if(b > a) {
      long long t = a; a = b; b = t;
    }
    count += a/b;
    a %= b;
  }
  cout << count << endl;
}
