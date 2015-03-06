// Petya and Strings

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string a, b; cin >> a >> b;

  for(int i = 0; i < a.length(); i++) a[i] = tolower(a[i]);
  for(int i = 0; i < b.length(); i++) b[i] = tolower(b[i]);

  if(lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())) cout << -1 << endl;
  else if(a == b) cout << 0 << endl;
  else cout << 1 << endl;
}
