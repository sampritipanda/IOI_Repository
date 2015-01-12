// Misha and Changing Handles

#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
  int Q; cin >> Q;
  set<string> final_handles;
  map<string, string> mappings;

  while(Q--){
    string old_h, new_h;
    cin >> old_h >> new_h;
    if(final_handles.find(old_h) == final_handles.end()){
      final_handles.insert(new_h);
      mappings[new_h] = old_h;
    }
    else {
      final_handles.erase(old_h);
      final_handles.insert(new_h);
      mappings[new_h] = mappings[old_h];
    }
  }

  cout << final_handles.size() << endl;
  for(auto it: final_handles){
    cout << mappings[it] << " " << it << endl;
  }
}
