#include <iostream>
#include <vector>
using namespace std;
int a[500010];

  vector <int> v;

int main() {
  // your code goes here
  int n;
  cin>>n;
  for (int i=1; i<=n; i++){
    cin>>a[i];
    a[i]+=34;
  } 
  
  v.clear();
  v.push_back(0);
  for (int i=1; i<=n; i++){
    if (a[i]==a[i-1] or a[i]==a[i+1]) v.push_back(i);
  }
  v.push_back(n+1);
  int ans= 1000000;
  for (int i=0; i<v.size()-1; i++){
    ans= min((v[i+1]-v[i]-1)/2, ans);
  }
  cout<<ans<<endl;
  
  
  return 0;
}
