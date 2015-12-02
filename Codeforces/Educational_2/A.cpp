#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> words;
vector<int> numbers;
string A;

void insert(string s) {
  bool number = true;
  for(int i = 0; i < s.length(); i++) {
    if(!(s[i] >= '0' && s[i] <= '9')) {
      number = false; break;
    }
  }
  if(s.size() == 0) number = false;

  if(number && to_string(stoi(s)) != s) number = false;

  if(number) {
    numbers.push_back(stoi(s));
  }
  else {
    words.push_back(s);
  }
}

int main() {
  cin >> A;

  string curr = "";
  for(int i = 0; i < A.length(); i++) {
    if(A[i] == ',' || A[i] == ';') {
      insert(curr);
      curr = "";
    }
    else {
      curr += A[i];
    }
  }
  insert(curr);

  if(numbers.size() == 0) cout << "-" << endl;
  else {
    cout << "\"";
    for(int i = 0; i < numbers.size() - 1; i++) cout << numbers[i] << ",";
    cout << numbers[numbers.size() - 1] << "\"" << endl;
  }

  if(words.size() == 0) cout << "-" << endl;
  else {
    cout << "\"";
    for(int i = 0; i < words.size() - 1; i++) cout << words[i] << ",";
    cout << words[words.size() - 1] << "\"" << endl;
  }
}
