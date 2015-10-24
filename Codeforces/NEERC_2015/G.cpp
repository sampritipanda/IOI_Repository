#include <bits/stdc++.h>
#define ll long long
#define rf freopen("inp.in","r",stdin)

using namespace std;

const int MAX = 222222;

struct candidate{
  int prep_time;
  int work_time;
  int index;
  candidate(){ prep_time = work_time = index = 0;}
};

struct work{
  int work_time;
  int index;
  work() { work_time = index = 0; }
};



candidate A[MAX];
work      W[MAX];

int N , M;
int ANS[MAX];
ll ST[ 4 * MAX ];
ll  V[ 4 * MAX ];

bool sort_time( work a , work b ){
  if( a.work_time == b.work_time )
    return a.index < b.index;
  return a.work_time > b.work_time;
}

bool sort_candidates( candidate a , candidate b ){
  return a.prep_time > b.prep_time ;
}

inline void upd( int node , int l , int r , int pos , int val ){

  V[node]++;

  if( l == r ){
    ST[node] = val;
    return;
  }

  int mid = ( l + r ) >> 1;

  if( mid >= pos ) upd( node + node , l , mid , pos , val );
  else             upd( node + node + 1 , mid + 1 , r , pos , val );

  ST[node] = ST[node + node] + ST[node + node + 1];
}

inline int query( int node , int l , int r, int qs , int qe){

  if( l == r ){
    if( qs + qe <= ST[node] )
      return l;
    return 0;
  }

  ll lc = ST[ node + node ];
  int mid = ( l + r ) >> 1;

  ll val = lc - V[ node + node] * 1LL * qs;

  if( val >= qe )
    return query( node + node , l , mid , qs , qe);
  else
    return query( node + node + 1, mid + 1 , r , qs , (int)(qe - val) );
}

int main(){


  cin.tie(0); ios::sync_with_stdio(0);

  cin >> N >> M;

  for( int i = 1 ; i <= M ; i++){
    int x;
    cin >> x;
    W[i].work_time = x;
    W[i].index     = i;
  }

  sort( W + 1 , W + 1 + M , sort_time );

  for( int i = 1 ; i <= N ; i++){
    int x , y;
    cin >> x >> y;
    A[i].prep_time = x;
    A[i].work_time = y;
    A[i].index     = i;
  }

  sort( A + 1 , A + 1 + N , sort_candidates );
  int cur = 1;

  for( int i = 1 ; i <= N ; i++ ){
    while( cur <= M and W[cur].work_time >= A[i].prep_time ){
      upd(1,1,M,W[cur].index,W[cur].work_time);
      cur++;
    }
    ANS[A[i].index] = query(1,1,M,A[i].prep_time,A[i].work_time);
  }

  for(int i = 1 ; i <= N ; i++)
    cout << ANS[i] << ' ';

  cout << endl;

}
