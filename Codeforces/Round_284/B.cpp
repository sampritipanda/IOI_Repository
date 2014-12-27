// Lecture

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int N, M; scanf("%d %d", &N, &M);
  map<string, string> dic;
  
  for(int i = 0; i < M; i++){
	string first, second;
	cin >> first >> second;
	dic[first] = second;
  }
  
  for(int i = 0; i < N; i++){
	string first; cin >> first;
	string second = dic[first];
	if(first.size() == second.size()) cout << first;
	else if(first.size() < second.size()) cout << first;
	else cout << second;
	
	if(i < N - 1) cout << " ";
	else cout << "\n";
  }
}
