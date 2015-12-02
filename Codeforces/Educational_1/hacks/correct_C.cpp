#include <bits/stdc++.h>

using namespace std;

struct vec
{
    int x, y, i;
    double ang;
    int dot(const vec& other) const
    {
            return x*other.x+y*other.y;
        }
    long double mag() const
    {
            return sqrtl(x*x+y*y);
        }
    bool operator< (const vec& other) const
    {
            return ang<other.ang;
        }
} A[100000];

int N;

bool compare(vec a, vec b, vec c, vec d)
{
    return a.dot(b)*c.mag()*d.mag()>c.dot(d)*a.mag()*b.mag();
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].x, &A[i].y), A[i].ang=atan2(A[i].y, A[i].x), A[i].i=i+1;
    sort(A, A+N);
    vec ans1=A[0], ans2=A[N-1];
    for(int i=0; i<N-1; i++)
        if(compare(A[i], A[i+1], ans1, ans2))
            ans1=A[i], ans2=A[i+1];
    printf("%d %d\n", ans1.i, ans2.i);
    return 0;
}
