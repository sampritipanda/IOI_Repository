 
#include <bits/stdc++.h>
#define F first
#define S second
#define PII pair<int,int>
 
using namespace std;
 
const int MAX = 4444 ;
const int INF = 1e9 + 6; 
int N;
int D[MAX] , V[MAX] , P[MAX];

int main(){
        
    cin.tie(0) , ios::sync_with_stdio(0);
    
    int N;
    
    cin >> N;
    for( int i = 1 ; i <= N ; i++ )
        cin >> V[i] >> D[i] >> P[i];

    for( int i = 1 ; i <= N ; i++ ){
        if( P[i] == INF ) continue;
        int c = 0;
        int add = V[i];
        bool rekt = false;
        for( int j = i + 1 ; j <= N ; j++){
            if( P[j] == INF ) continue;
            P[j] = P[j] - add + c  ;
            if(!rekt) c++;
            if( c == V[i] + 1 ){
                add -= V[i]; 
                c = 0;
                rekt = 1;
            }
            if( P[j] < 0 ) P[j] = INF , add += D[j];
        }
    }

    int rem = 0;

    for( int i = 1 ; i <= N ; i++ )
        if( P[i] != INF ) rem++;
    
    cout << rem << endl;

    for( int i = 1 ; i <= N ; i++ ){
        if( P[i] != INF )
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
