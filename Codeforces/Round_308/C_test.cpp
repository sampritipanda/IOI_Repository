#include <bits/stdc++.h>

#define rf freopen("inp.in", "r", stdin)

#define MOD 1000000007

#define INF 1000000009

#define pb push_back

#define mp make_pair

#define ll long long

#define MAX 45

#define LN 20

using namespace std;





int main() 

{



  int W , N ;

  cin >> W >> N ;

  int copy = N ;

  int flag = 0;



  while( copy!=0 and copy >= W ){

    if(copy % W > 1) flag=1;

    copy/=W;

  }



  if(copy!=0){

    copy= W - copy;

    while(copy){

      if(copy % W > 1)flag=1;

      copy/=W;

    }

  }



  if(flag!=1) cout << "YES" << endl;

  else        cout << "NO" <<endl;

  return 0;

}
