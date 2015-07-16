#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
bool cracked[502][502];
int visit_count[502][502];
int r1, c1, r2, c2;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool dfs(int r, int c){
  if(r == r2 && c == c2){
    int a = 4;
  }

  visit_count[r][c]++;
  if(visit_count[r][c] > 2) return false;

  if(r == r2 && c == c2){
    if(cracked[r][c] && visit_count[r][c] >= 1) return true;
    else if(!cracked[r][c] && visit_count[r][c] >= 2) return true;
  }
  else {
    if(cracked[r][c] && visit_count[r][c] >= 1) return false;
    else if(!cracked[r][c] && visit_count[r][c] >= 2) return false;
  }

  for(int i = 0; i < 4; i++){
    if((r + dr[i]) < 0 || (r + dr[i]) == n) continue;
    if((c + dc[i]) < 0 || (c + dc[i]) == m) continue;
    if(dfs(r + dr[i], c + dc[i])) return true;
  }

  return false;
}

int main() {
  memset(cracked, false, sizeof cracked);
  memset(visit_count, 0, sizeof visit_count);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string temp; cin >> temp;
    for(int j = 0; j < m; j++){
      cracked[i][j] = temp[j] == 'X';
    }
  }
  cin >> r1 >> c1; r1--; c1--;
  cin >> r2 >> c2; r2--; c2--;
  visit_count[r1][c1] = -1;

  if(dfs(r1, c1)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
