// Game With Sticks

#include <iostream>

using namespace std;

string solve(int N, int M, string curr) {
  string nex = (curr == "Akshat" ? "Malvika" : "Akshat");
  if(N == 0 || M == 0) return nex;

  return solve(N - 1, M - 1, nex);
}

int main() {
  int N, M; cin >> N >> M;

  cout << solve(N, M, "Akshat") << endl;

}
