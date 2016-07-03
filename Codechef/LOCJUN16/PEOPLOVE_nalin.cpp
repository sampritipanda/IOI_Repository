#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

vector<int> deg, orientation;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> edge;

void brute(int L, int R)
{
  bool done1 = true, done2 = true;
  //cout << L << " " << R << "\n";
  while(L != R)
  {
    //cout << L << " " << R << "\n";
    done1 = done2 = false;
    for(auto it: graph[L])
    {
      if(orientation[it.second] == -1)
      {
        orientation[it.second] = L;
        deg[it.first]--;
        deg[L]++;
        L = it.first;
        done1 = true;
        break;
      }
    }
    for(auto it: graph[R])
    {
      if(orientation[it.second] == -1)
      {
        orientation[it.second] = it.first;
        deg[it.first]++;
        deg[R]--;
        R = it.first;
        done2 = true;
        break;
      }
    }
    if(!done1 && !done2)
    {
      break;
    }
  }
}

int main(void)
{
  // printf("BOTH_SUBTASKS\n");
  int t;
  scanf("%d", &t);
  while(t--) {
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  graph.clear(); graph.resize(n);
  deg.clear(); deg.resize(n);
  edge.clear(); edge.resize(m);
  orientation.clear(); orientation.resize(m, -1);


  for(int i = 0;i < m;i++)
  {
    scanf("%d%d", &u, &v);
    u--; v--;
    graph[u].push_back({v, i});
    graph[v].push_back({u, i});
    orientation[i] = -1;
    edge[i] = {u, v};
  }

  for(int i = 0;i < m;i++)
  {
    if(orientation[i] == -1)
    {
      orientation[i] = edge[i].second;
      deg[edge[i].second]++;
      deg[edge[i].first]--;
      //cout << i << "\n";
      brute(edge[i].first, edge[i].second);
    }
  }
  int res = 0;
  for(auto it: deg)
  {
    //cout << it << "\n";
    res = max(res, abs(it));
  }
  
  //cout << "\n";
  assert(res <= 1);
  printf("%d\n", res);
  for(int i = 0;i < m;i++)
  {
    if(orientation[i] == edge[i].first) printf("%d %d\n", edge[i].first+1, edge[i].second+1);
    else printf("%d %d\n", edge[i].second+1, edge[i].first+1);
  }
  }
}
