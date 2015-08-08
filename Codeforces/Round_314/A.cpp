// Lineland Mail

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<long long> cities;

int main() {
  int N; cin >> N;

  cities.clear();

  for(int i = 0; i < N; i++) {
    int A; cin >> A;
    cities.push_back(A);
  }

  cout << cities[1] - cities[0] << " " << cities[N - 1] - cities[0] << endl;
  for(int i = 1; i < N - 1; i++) {
    cout << min(cities[i] - cities[i - 1], cities[i + 1] - cities[i]) << " " << max(cities[i] - cities[0], cities[N - 1] - cities[i]) << endl;
  }
  cout << cities[N - 1] - cities[N - 2] << " " << cities[N - 1] - cities[0] << endl;
}
