#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef long long int lli;

vector<lli> W;

int main(void)
{
	lli t;
	scanf("%lld", &t);
	for(lli tt = 1;tt <= t;tt++)
	{
		lli l, n, m, d, res = 0;
		pair<lli, lli> top, qq;
		scanf("%lld%lld%lld%lld", &l, &n, &m, &d);
		W.clear(); W.resize(n);
		for(lli i = 0;i < n;i++) scanf("%lld", &W[i]);
		sort(W.begin(), W.end());

		if(m >= l)
		{
			set<pair<lli, lli> > cur;
			for(lli i = 0;i < n;i++) cur.insert({W[i], i});

			while(l--)
			{
				//cout << "hello\n";
				//for(auto it: cur) cout << it.first << " " << it.second << "\n";
				top = *cur.begin();
				//cout << top.first << " " << W[top.second] << "\n";
				cur.erase(cur.begin());
				res = max(res, top.first);
				cur.insert({top.first+W[top.second], top.second});
			}
			printf("Case #%lld: %lld\n", tt, res+d);
		}
		else
		{
			set<pair<lli, lli> > wash;
			deque<pair<lli, lli> > dry;
			for(lli i = 0;i < n;i++) wash.insert({W[i], i});
			for(lli i = 0;i < m;i++) dry.push_back({d, i});

			while(l--)
			{
				//cout << "hello\n";
				//for(auto it: wash) cout << it.first << " " << it.second << "\n";
				//for(auto it: dry) cout << it.first << " " << it.second << "\n";
				top = *wash.begin();
				wash.erase(wash.begin());
				wash.insert({top.first+W[top.second], top.second});
				qq = dry.front();
				dry.pop_front();
				res = max(res, max(qq.first, top.first+d));
				dry.push_back({max(qq.first, top.first+d)+d, qq.second});
			}
			printf("Case #%lld: %lld\n", tt, res);
		}
	}
}
