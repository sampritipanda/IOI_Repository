#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int> > edges;

int main(){
  edges.clear();
	int K; cin >> K;

  if(K % 2 == 0) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for(int i = 1; i <= K - 1; i++){
      for(int j = K; j <= 2*K - 2; j++) {
        edges.push_back({i , j});
      }
    }

    for(int i = 2*K - 1; i <= 3*K - 3; i++) {
      for(int j = 3*K - 2; j <= 4*K - 4; j++) {
        edges.push_back({i, j});
      }
    }

    for(int i = K; i <= 2*K - 2; i++) {
      edges.push_back({4 * K - 3, i});
    }

    for(int i = 2*K - 1; i <= 3*K - 3; i++) {
      edges.push_back({4*K - 2, i});
    }

    for(int i = 1; i <= K - 1; i = i + 2) {
      edges.push_back({i, i + 1});
    }

    for(int i = 3*K - 2; i <= 4*K - 4; i = i + 2) {
      edges.push_back({i, i + 1});
    }
    edges.push_back({4*K  -3, 4*K - 2});

    cout << 4*K - 2 << " " << edges.size() << endl;
    for(auto it: edges) {
      cout << it.first << " " << it.second << endl;
    }
  }
}
