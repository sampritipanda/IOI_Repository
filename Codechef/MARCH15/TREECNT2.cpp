// Counting on a Tree

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_V 100000
#define LOG2_MAXV 17

int N;
vector<int> L[MAX_V],W[MAX_V];
pair<int, int> edges[MAX_V];

int Q[MAX_V],head,tail;
bool visited[MAX_V];
int P[MAX_V][LOG2_MAXV],level[MAX_V],dist[MAX_V][LOG2_MAXV];

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

void bfs(){
    head = 0; tail = 0;
    memset(visited,false,sizeof(visited));
    
    P[0][0] = -1;
    level[0] = 0;
    dist[0][0] = -1;
    Q[0] = 0; tail = 1;
    visited[0] = true;
    
    while(head<tail){
        int pos = Q[head];
        ++head;
        
        for(int i = L[pos].size()-1;i>=0;--i){
            int next = L[pos][i];
            
            if(!visited[next]){
                P[next][0] = pos;
                level[next] = level[pos]+1;
                dist[next][0] = W[pos][i];
                Q[tail] = next; ++tail;
                visited[next] = true;
            }
        }
    }
}

void lca_init(){
    bfs();
    
    for(int j = 1;(1<<j)<N;++j){
        for(int i = 0;i<N;++i){
            if(P[i][j-1]!=-1){
                P[i][j] = P[P[i][j-1]][j-1];
                dist[i][j] = gcd(dist[i][j-1],dist[P[i][j-1]][j-1]);
            }
        }
    }
}

int LCA(int p, int q){
    if(level[p]<level[q]) swap(p,q);
    
    int log = 0;
    while((1<<log)<=level[p]) ++log;
    --log;
    
    int ans = 0;
    
    for(int i = log;i>=0;--i){
        if(level[p]-(1<<i)>=level[q]){
            ans = gcd(dist[p][i], ans);
            p = P[p][i];
        }
    }
    
    if(p==q) return ans;
    
    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            ans = gcd(gcd(dist[p][i],dist[q][i]), ans);
            p = P[p][i];
            q = P[q][i];
        }
    }
    
    ans = gcd(gcd(dist[p][0],dist[q][0]), ans);
    
    return ans;
}

int get_count(){
  int count = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      if(LCA(i,j) == 1) count++;
    }
  }
  return count;
}

int main(){
    scanf("%d",&N);
    
    for(int i = 1,u,v,w;i<N;++i){
        scanf("%d %d %d",&u,&v,&w);
        u--; v--;
        L[u].push_back(v);
        W[u].push_back(w);
        L[v].push_back(u);
        W[v].push_back(w);
        edges[i - 1] = {u, v};
    }
    
    int Q;
    scanf("%d",&Q);
    
    lca_init();
    
    printf("%d\n", get_count());
    for(int q = 0,a,c;q<Q;++q){
      scanf("%d %d", &a, &c);
      a--; int u = edges[a].first, v = edges[a].second;
      for(int x = 0; x < L[u].size(); x++){
        if(L[u][x] == v) {
          W[u][x] = c; break;
        }
      }
      for(int x = 0; x < L[v].size(); x++){
        if(L[v][x] == u) {
          W[v][x] = c; break;
        }
      }
      lca_init();
      printf("%d\n", get_count());
    }
    
    return 0;
}

