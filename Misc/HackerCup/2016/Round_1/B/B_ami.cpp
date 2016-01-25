#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

int main()
{
	ll t;
	cin>>t;
	for(ll tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		ll l,n,m,d;
		cin>>l>>n>>m>>d;
		ll arr[n];
		for(ll i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		ll L = -1, R = 1000000000000000000LL;
		while(R - L > 1)
		{
			ll M = (L + R) / 2;
			//cout<<M<<endl;
			ll cnt = 0;
			for(ll i = 0; i < n; i++)
				cnt += M / arr[i]  ;
			if(cnt >= l)
				R = M;
			else
				L = M;
		}
		vector<ll> lau;
		ll ind=0;
		for(ll i=0;i<n;i++)
		{
			ll num=R/arr[i];
			for(ll j=1;j<=num;j++)
				lau.push_back(j*arr[i]);
		}
		sort(lau.begin(),lau.end());
		ind=lau.size();
		ll limit= ind%m==0? m: ind%m;
		ll upper=0;
		for(ll i=0;i<ind;)
		{
			i=min(limit,ind);
			upper=max(upper,lau[i-1])+d;
			//cout<<upper<<endl;
			limit*=2;
		}			
		cout<<upper<<endl;
		//cout<<R<<endl;
	}
	return 0;
}
