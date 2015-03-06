// Time to Study Graphs with Chef

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

long long modpow(long long base, long long exp){
  base %= MOD;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return result;

}

unsigned long long find_hash(pair<long long, long long> a){
  unsigned long long hash = 0xAAAAAAAA;
  hash ^= ((0 & 1) == 0) ? (  (hash <<  7) ^ a.first * (hash >> 3)) : (~((hash << 11) + (a.first ^ (hash >> 5))));
  hash ^= ((1 & 1) == 0) ? (  (hash <<  7) ^ a.second * (hash >> 3)) : (~((hash << 11) + (a.second ^ (hash >> 5))));
  return hash;
}

int main() {
  long long N, M, K; cin >> N >> M >> K;
  set<long long> edge_nodes_layers_set; vector<long long> edge_nodes_layers;
  unordered_map<long long, vector<pair<long long, long long> > > incoming_edges_by_column;
  unordered_map<unsigned long long, vector<pair<long long, long long> > > incoming_edges;
  unordered_map<long long, set<long long> > outgoing_edges;
  unordered_map<unsigned long long, long long> edge_values;

  for(int i = 0; i < K; i++){
    long long e0, e1, e2, e3; cin >> e0 >> e1 >> e2 >> e3;
    edge_nodes_layers_set.insert(e0); edge_nodes_layers_set.insert(e2);
    incoming_edges_by_column[e2].push_back({e0, e1});
    incoming_edges[find_hash({e2, e3})].push_back({e0, e1});
    outgoing_edges[e0].insert(e1);
  }
  for(auto it: edge_nodes_layers_set) edge_nodes_layers.push_back(it);

  long long prev_sum, curr_sum;
  edge_values[find_hash({0, 0})] = 1;
  prev_sum = 1;

  // N == 1
  curr_sum = (prev_sum * M) % MOD;
  for(auto v: incoming_edges_by_column[1]) curr_sum = (curr_sum + edge_values[find_hash({v.first, v.second})]) % MOD;
  for(auto v: outgoing_edges[1]) {
    long long temp_sum = 1;
    for(auto b: incoming_edges[find_hash({1, v})]){
      temp_sum += edge_values[find_hash({b.first, b.second})];
    }
    edge_values[find_hash({1, v})] = temp_sum;
  }
  prev_sum = curr_sum;
  // N == 1 - end

  long long start = 0, last_N = 1;
  for(auto it: edge_nodes_layers){
    if(it > 1) break;
    start++;
  }

  if(!edge_nodes_layers.empty() && *edge_nodes_layers.rbegin() == N + 1) edge_nodes_layers.pop_back();

  for(int i = start; i < edge_nodes_layers.size(); i++){
    long long curr_layer = edge_nodes_layers[i];
    curr_sum = (prev_sum * modpow(M, curr_layer - last_N)) % MOD;
    for(auto v: incoming_edges_by_column[curr_layer]) curr_sum = (curr_sum + edge_values[find_hash({v.first, v.second})]) % MOD;
    for(auto v: outgoing_edges[curr_layer]) {
      long long temp_sum = (prev_sum * modpow(M, curr_layer - last_N - 1)) % MOD;
      for(auto b: incoming_edges[find_hash({curr_layer, v})]){
        temp_sum += edge_values[find_hash({b.first, b.second})];
      }
      edge_values[find_hash({curr_layer, v})] = temp_sum;
    }
    prev_sum = curr_sum;
    last_N = curr_layer;
  }

  curr_sum = (prev_sum * modpow(M, N - last_N)) % MOD;
  for(auto v: incoming_edges_by_column[N + 1]) curr_sum = (curr_sum + edge_values[find_hash({v.first, v.second})]) % MOD;

  cout << curr_sum << endl;
}
