#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    long long allocated_memory = 0, total_allocations = 0;
    for(int i = 0; i < N; i++) {
      int M; cin >> M;
      if(M > allocated_memory) {
        total_allocations += M - allocated_memory;
      }
      allocated_memory = M;
    }
    cout << total_allocations << endl;
  }
}
