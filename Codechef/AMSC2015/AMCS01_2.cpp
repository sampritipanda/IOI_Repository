#include <bits/stdc++.h>
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x))+1)
using namespace std;
typedef long long ll;
typedef vector <int> vii;
ll t,n,u,v,m,q,r,ql,qr,k,l,s,x,y,w;
const int N=1e5+500;
int sz[N],pos[N],rpos[N],dep[N];
vii adj[N];
int timer=0;
struct node{
  int d;
  int lz;
  int ct;
  node (int d,int lz,int ct) : d(d),lz(lz),ct(ct) { }
  node () {}
}tree[4 * N];
node operator+(node a,node b) {
  if (a.d+a.lz==b.d+b.lz) {
    return node(a.d+a.lz,0,a.ct+b.ct);
  }
  else if (a.d+a.lz > b.d+b.lz) {
    return node(a.d+a.lz,0,a.ct);
  }
  else return node(b.d+b.lz,0,b.ct);
}
void init(int i,int l,int r) {
  if (l==r) {
    tree[i].d=dep[rpos[l]];
    tree[i].lz=0;
    tree[i].ct=1;
    return;
  }
  int mid=(l+r) / 2;
  init(l(i),l,mid);
  init(r(i),mid+1,r);
  tree[i]=tree[l(i)]+tree[r(i)];
}
void push(int i) {
  int left=l(i);
  int right=r(i);
  tree[left].lz+=tree[i].lz;
  tree[right].lz+=tree[i].lz;
  tree[i].d+=tree[i].lz;
  tree[i].lz=0;
}
void modify(int l,int r,int i,int rl,int rr,int add) {
  if (rl>rr) return;
  if (rl<=l && r<=rr) tree[i].lz+=add;
  else if (l>rr || rl>r) return;
  else {
    int mid=(l+r) / 2;
    if (tree[i].lz) push(i);
    modify(l,mid,l(i),rl,rr,add);
    modify(mid+1,r,r(i),rl,rr,add);
    tree[i]=tree[l(i)]+tree[r(i)];
  }
}
node query(int l,int r,int i,int rl,int rr) {
  if (rl>rr) return node(0,0,0);
  if (rl<=l && r<= rr) return tree[i];
  else if (l > rr || rl > r) {
    return node(0,0,0);
  }
  else {
    int mid=(l+r) / 2;
    if (tree[i].lz) push(i);
    return query(l,mid,l(i),rl,rr)+query(mid+1,r,r(i),rl,rr);
  }
}
void dfs(int v,int p) {
  pos[v]=timer++;
  rpos[timer-1]=v;
  dep[v]=dep[p]+1;
  sz[v]=1;
  for (int i=0; i < adj[v].size(); ++i) {
    int u=adj[v][i];
    if (u==p) continue;
    dfs(u,v);
    sz[v]+=sz[u];
  }
}
node ans[N];
void solve(int v,int p) {
  ans[v]=query(0,n-1,0,0,n-1);
  /*for (int i=0; i < n; ++i) {
    node k=query(0,n-1,0,i,i);
    cout << k.d << " " << k.ct << " " << k.lz << " ";
    cout << '\n';
    }*/
  for (int i=0; i < adj[v].size(); ++i) {
    int u=adj[v][i];
    if (u==p) continue;
    modify(0,n-1,0,pos[u],pos[u]+sz[u]-1,-1);
    modify(0,n-1,0,0,pos[u]-1,1);
    modify(0,n-1,0,pos[u]+sz[u],n-1,1);
    solve(u,v);
    modify(0,n-1,0,pos[u],pos[u]+sz[u]-1,1);
    modify(0,n-1,0,0,pos[u]-1,-1);
    modify(0,n-1,0,pos[u]+sz[u],n-1,-1);
  }
}
int main() {
  cin>>n;
  for (int i=0; i < n-1; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dep[n]=0;
  dfs(0,n);
  init(0,0,n-1);
  solve(0,n);
  for (int i=0; i < n; ++i) {
    cout<<ans[i].ct<<" ";
    //cout<<ans[i].d<<" "<<ans[i].lz<<'\n';
  }
  cout<<'\n';
  return 0;
} 
