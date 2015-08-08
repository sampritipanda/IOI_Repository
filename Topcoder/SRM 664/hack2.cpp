/*
By : Yash Kumar
Dhirubhai Ambani Institute Of Information And Communication Technology, Gandhinagar (DA-IICT GANDHINAGAR)
2nd Year ICT BTECH student
*/
#include<bits/stdc++.h>

#define lli long long int
#define llu unsigned long long int
#define all(v) v.begin(),v.end()

const double EPS = 1e-24;
const lli MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
lli INFINF = 9223372036854775807;

template <class T>T Max2(T a,T b){return a<b?b:a;}
template <class T>T Min2(T a,T b){return a<b?a:b;}
template <class T>T Max3(T a,T b,T c){return Max2(Max2(a,b),c);}
template <class T>T Min3(T a,T b,T c){return Min2(Min2(a,b),c);}
template <class T>T Max4(T a,T b,T c,T d){return Max2(Max2(a,b),Max2(c,d));}
template <class T>T Min4(T a,T b,T c,T d){return Min2(Min2(a,b),Max2(c,d));}

using namespace std;

bool xbeforey[45][45];
int n;
int cnt=0;
vector<int> T;
vector<int> I;
int M[45];

void mergesort(int l,int r)
{
    /*cout<<l<<","<<r<<"-> ";
    for(int i=0;i<n;i++)
        cout<<I[i]<<" ";
    cout<<"\n";*/

    if(l+1>=r)
        return ;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid,r);
    int p1=l,p2=mid;
    int sz=0;
    while( (p1<mid) || (p2<r) )
    {
        if(p1==mid)
        {
            M[sz++]=I[p2];
            p2++;
        }
        else if(p2==r)
        {
            M[sz++]=I[p1];
            p1++;
        }
        else
        {
            cnt++;
            if(xbeforey[I[p1]][I[p2]])
            {
                M[sz++]=I[p1];
                p1++;
            }
            else
            {
                M[sz++]=I[p2];
                p2++;
            }
        }
    }
    for(int i=l;i<r;i++)
        I[i]=M[i-l];
    return ;
}

struct BearSortsDiv2{
    double getProbability(vector <int> seq)
    {
        T=seq;
        n=T.size();
        for(int i=0;i<seq.size();i++)
            for(int j=i+1;j<seq.size();j++)
                xbeforey[seq[i]][seq[j]]=true;
        for(int i=0;i<n;i++)
            I.push_back(i+1);
        mergesort(0,n);
        double ans=1;
        for(int i=1;i<=cnt;i++)
            ans*=0.5;
        return log(ans);
    }
};

int main() {
  BearSortsDiv2 test;
  cout << test.getProbability({7, 6, 2, 11, 19, 5, 17, 15, 8, 4, 14, 3, 20, 9, 10, 18, 13, 12, 1, 16}) << endl;
}


