#include <string>
#include <iostream>

using namespace std;

class Cyclemin {
  public:
  string bestmod(string s, int k) {
    int N = s.length();
    string smallest = s;
    string curr_shift = s;
    do {
      string change = curr_shift;
      int i = 0, j = k;
      while(i < N && j > 0) {
        if(change[i] != 'a') {
          change[i] = 'a';
          j--;
        }
        i++;
      }
      if(lexicographical_compare(change.begin(), change.end(), smallest.begin(), smallest.end())) smallest = change;
      char last = curr_shift[N - 1];
      curr_shift.pop_back();
      curr_shift.insert(curr_shift.begin(), last);
    } while(curr_shift != s);
    return smallest;
  }
};

int main() {
  Cyclemin test;
  cout << test.bestmod("sgsgaw", 1) << endl;
}
