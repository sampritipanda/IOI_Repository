// Matched Brackets 2

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
  int N; cin >> N;

  int alternate_depth = 0, max_alt_depth = 0;
  int round_depth = 0, round_count = 0, max_round_count = 0;
  int square_depth = 0, square_count = 0, max_square_count = 0;

  stack<int> S;
  while(!S.empty()) S.pop();

  for(int i = 0; i < N; i++) {
    int a; cin >> a;

    if(a == 1) {
      round_depth++;
      round_count++;
      if(square_depth > 0) square_count++;

      if(round_count > max_round_count) max_round_count = round_count;
      if(square_count > max_square_count) max_square_count = square_count;

      if(S.empty() || S.top() == 3) alternate_depth++;
      if(alternate_depth > max_alt_depth) max_alt_depth = alternate_depth;
    }
    else if(a == 2) {
      round_depth--;
      round_count++;
      if(square_depth > 0) square_count++;

      if(round_count > max_round_count) max_round_count = round_count;
      if(square_count > max_square_count) max_square_count = square_count;

      if(round_depth == 0) round_count = 0;
      S.pop();
      if(S.empty() || S.top() == 3) alternate_depth--;
    }
    else if(a == 3) {
      square_depth++;
      square_count++;
      if(round_depth > 0) round_count++;

      if(round_count > max_round_count) max_round_count = round_count;
      if(square_count > max_square_count) max_square_count = square_count;

      if(S.empty() || S.top() == 1) alternate_depth++;
      if(alternate_depth > max_alt_depth) max_alt_depth = alternate_depth;
    }
    else {
      square_depth--;
      square_count++;
      if(round_depth > 0) round_count++;

      if(round_count > max_round_count) max_round_count = round_count;
      if(square_count > max_square_count) max_square_count = square_count;

      if(square_depth == 0) square_count = 0;
      S.pop();
      if(S.empty() || S.top() == 1) alternate_depth--;
    }

    if(a == 1 || a == 3) S.push(a);
  }

  cout << max_alt_depth << " " << max_round_count << " " << max_square_count << endl;
}
