#include <iostream>

using namespace std;

int A[1000];
bool vis[1000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) vis[i] = false;

  int done = 0, count = 0, i = 0;
  do {
    if(A[i] <= done && !vis[i]) {
      done++;
      vis[i] = true;
    }
    if(count & 1) i--;
    else i++;

    if(count & 1 && i == -1 && done < N) i = 0, count += 1;
    else if(count % 2 == 0 && i == N && done < N) i = N - 1, count += 1;
  } while(done < N);

  cout << count << endl;
}
