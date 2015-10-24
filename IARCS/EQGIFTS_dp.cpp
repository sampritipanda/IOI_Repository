// Equal Gifts

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N;
vector<pair<int, int> > books;
int dp[150][2];

int solve(int i, int j) {
  if(i == N) return 0;
  if(dp[i][j] != -1) return dp[i][j];

  int curr_ans;
  if(j == 0) {
    int a = books[i].first + solve(i + 1, 0) - books[i].second;
    int b = books[i].first + solve(i + 1, 1) - books[i].second;

    if(abs(a) <= abs(b)) curr_ans = a;
    else curr_ans = b;
  }
  else {
    int a = books[i].second + solve(i + 1, 0) - books[i].first;
    int b = books[i].second + solve(i + 1, 1) - books[i].first;

    if(abs(a) <= abs(b)) curr_ans = a;
    else curr_ans = b;
  }

  return dp[i][j] = curr_ans;
}

bool sort_compare(pair<int, int> a, pair<int, int> b){
    return abs(a.second - a.first) > abs(b.second - b.first);
}

int main() {
	scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    dp[i][0] = dp[i][1] = -1;
  }

	for(int i = 0; i < N; i++){
		int a, b; scanf("%d %d", &a, &b);
		books.push_back(make_pair(a, b));
	}
	sort(books.begin(), books.end(), sort_compare);

	printf("%d\n", min(abs(solve(0, 0)), abs(solve(0, 1))));
  int a = 4;
}
