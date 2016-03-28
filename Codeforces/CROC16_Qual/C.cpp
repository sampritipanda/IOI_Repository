#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

long long R1 = 1000010029LL, R2 = 1002010033LL, R3 = 1000510037LL;
long long MOD1 = 999989981LL, MOD2 = 999989957LL, MOD3 = 999979957LL;

map<string, set<string> > M1;
// map<vector<long long>, vector<string> > M2;
map<set<string>, vector<string> > M2;

string hostname(string S) {
  string ans = "";
  for(int i = 7; S[i] != '/' && i < S.length(); i++) {
    ans += S[i];
  }
  return ans;
}

string path(string S) {
  string ans = "";
  bool start = false;
  for(int i = 7; i < S.length(); i++) {
    if(S[i] == '/') start = true;
    if(start) ans += S[i];
  }
  return ans;
}

long long hash_string(long long hash, string S, long long exp, long long mod) {
  for(char c: S) {
    hash = ((hash * exp) + int(c)) % mod;
  }
  return hash;
}

vector<long long> find_hash(set<string>& A) {
  long long hash1 = 0, hash2 = 0, hash3 = 0;
  for(string S: A) {
    hash1 = hash_string(hash1, S, R1, MOD1);
    hash2 = hash_string(hash2, S, R2, MOD2);
    hash3 = hash_string(hash3, S, R3, MOD3);
  }
  return {hash1, hash2, hash3};
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    char temp[50]; scanf(" %s", temp);
    string S(temp);

    string H = hostname(S), P = path(S);
    if(P == "") P = " ";
    M1[H].insert(P);
  }

  for(auto it: M1) {
    // vector<long long> hashes = find_hash(it.second);
    M2[it.second].push_back(it.first);
  }

  int cnt = 0;
  for(auto it: M2) {
    if(it.second.size() > 1) cnt++;
  }

  printf("%d\n", cnt);
  for(auto it: M2) {
    if(it.second.size() > 1) {
      for(string S: it.second) {
        printf("http://%s ", S.c_str());
      }
      printf("\n");
    }
  }
}
