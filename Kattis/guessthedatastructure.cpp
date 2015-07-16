// I Can Guess the Data Structure!

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
  int N;
  while(scanf("%d", &N) != EOF){
    vector<pair<int, int> > operations;
    for(int i = 0; i < N; i++) {
      int a, b; cin >> a >> b;
      operations.push_back({a, b});
    }

    int count = 0;

    bool stack_possible = true;
    stack<int> S;
    for(auto it: operations){
      if(it.first == 1){
        S.push(it.second);
      }
      else {
        if(S.empty()){
          stack_possible = false;
          break;
        }
        else {
          int front = S.top(); S.pop();
          if(front != it.second){
            stack_possible = false;
            break;
          }
        }
      }
    }
    if(stack_possible) count++;

    bool queue_possible = true;
    queue<int> Q;
    for(auto it: operations){
      if(it.first == 1){
        Q.push(it.second);
      }
      else {
        if(Q.empty()){
          queue_possible = false;
          break;
        }
        else {
          int front = Q.front(); Q.pop();
          if(front != it.second){
            queue_possible = false;
            break;
          }
        }
      }
    }
    if(queue_possible) count++;

    bool priority_queue_possible = true;
    priority_queue<int> PQ;
    for(auto it: operations){
      if(it.first == 1){
        PQ.push(it.second);
      }
      else {
        if(PQ.empty()){
          priority_queue_possible = false;
          break;
        }
        else {
          int front = PQ.top(); PQ.pop();
          if(front != it.second){
            priority_queue_possible = false;
            break;
          }
        }
      }
    }
    if(priority_queue_possible) count++;

    if(count == 0) cout << "impossible" << endl;
    else if(count == 1){
      if(stack_possible) cout << "stack" << endl;
      else if(queue_possible) cout << "queue" << endl;
      else cout << "priority queue" << endl;
    }
    else cout << "not sure" << endl;
  }
}
