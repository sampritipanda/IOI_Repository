#include <iostream>
#include <algorithm>

using namespace std;

int A[1000000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  int P; cin >> P;

  long long count = 0;
  for(int i = 0; i < N; i++) {
    double avg = 0.0;
    for(int j = i; j < N; j++) {
      avg = (avg * (j - i) + A[j])/double(j - i + 1);
      if(avg >= P) count++;
    }
  }

  cout << count << endl;
}
