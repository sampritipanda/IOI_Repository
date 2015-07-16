#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int arr[300001];

int find_group(int a){
  if(a == arr[a]) return a;
  return arr[a] = find_group(arr[a]);
}

void merge(int a, int b){
  a = find_group(a);
  b = find_group(b);
  if(a != b) arr[b] = a;
}

void dfs(int a){
}

int main() {
  int N, M, V; cin >> N >> M >> V;

  for(int i = 0; i <= M; i++) arr[i] = i;
  vector<pair<int, int> > queries;

  for(int i = 0; i < V; i++){
    string s; cin >> s;
    string A_str = "", B_str = ""; char C; int A, B;
    int j = 0;
    while(s[j] == '<' || s[j] == '=') A_str += s[j++];
    C = s[j++];
    while(j < N) B_str += s[j++];
    A = stoi(A_str); B = stoi(B_str);

    if(C == '='){
      merge(A, B);
    }
    else {
      queries.push_back({A, B});
    }
  }

  vector<set<int> > graph(M + 1);
  for(auto it: queries){
    graph[find_group(it.first)].insert(find_group(it.second));
  }

}
