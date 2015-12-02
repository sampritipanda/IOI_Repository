#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
char s[10005],t[10005];
int m,l,r,k;
int main()
{
  scanf("%s",s+1);
  scanf("%d",&m);
  for(int qi=1;qi<=m;qi++)
  {
    scanf("%d%d%d",&l,&r,&k);
    k%=(r-l+1);
    for(int i=0;i<k;i++)
      t[i]=s[r-i];
    for(int i=r;i-k>=l;i--)
      s[i]=s[i-k];
    for(int i=0;i<k;i++)
      s[l+k-1-i]=t[i];
  }
  puts(s+1);
  return 0;
}
