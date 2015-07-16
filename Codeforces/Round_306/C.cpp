#include <iostream>
#include <string>

using namespace std;

int main(){
  string s; cin >> s;
  int N = s.size();
  for(int i = 0; i < N; i++){
    int v = s[i] - '0';
    if(v%8==0){cout<<"YES\n"<<v<<"\n";return 0;}
  }
  for(int i = 0 ; i < N ; i++){
    for(int j = i+1 ;  j < N; j++){
      int v = s[i]-'0';
      int w = s[j]-'0';
      int z = v*10 + w;
      if(z%8==0){cout<<"YES\n"<<z<<"\n";return 0;}
    }
  }
  for(int i = 0 ; i < N ; i++){
    for(int j = i+1 ;  j < N; j++){
      for(int k = j+1; k < N ; k++){
        int v = s[i]-'0';
        int w = s[j]-'0';
        int x = s[k]-'0';
        int lol = v*100 + w*10 + x;
        if(lol%8==0){cout<<"YES\n"<<lol<<"\n";return 0;}
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
