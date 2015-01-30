// Microscope

#include <stdio.h>
#include <cmath>
#include <utility>

using namespace std;

struct point {
    int x, y;
};

struct rect {
    point a, b, c, d;
    /*
      a ------- b
        |     |
        |     |
      d ------- c
    */
};

bool point_inside_rec(point p, rect r){
    return ((p.x >= r.a.x && p.x <= r.b.x) && (p.y >= r.a.y && p.y <= r.d.y));
}

int main() {
    //freopen("data", "r", stdin);

    int M, N; scanf("%d %d", &M, &N);
    int R, C; scanf("%d %d", &R, &C);
    int K; scanf("%d", &K);

    rect curr;
    curr.a.x = curr.a.y = 0;
    curr.b.x = C - 1; curr.b.y = 0;
    curr.c.x = C - 1; curr.b.y = R - 1;
    curr.d.x = 0; curr.d.y = R - 1;

    long long count = 0;
    for(int i = 0; i < K; i++){
        point p; int x, y; scanf("%d %d", &p.y, &p.x);
        if(point_inside_rec(p, curr)) continue;
        else {
            point a = curr.a, b = curr.b, c = curr.c, d = curr.d;
            if(p.x > b.x){
                int change = p.x - b.x;
                count += change;
                a.x += change; b.x += change; c.x += change; d.x += change;
            }
            else if(p.x < a.x){
                int change = a.x - p.x;
                count += change;
                a.x -= change; b.x -= change; c.x -= change; d.x -= change;
            }

            if(p.y > d.y){
                int change = p.y - d.y;
                count += change;
                a.y += change; b.y += change; c.y += change; d.y += change;
            }
            else if(p.y < a.y){
                int change = a.y - p.y;
                count += change;
                a.y -= change; b.y -= change; c.y -= change; d.y -= change;
            }

            curr.a = a, curr.b = b, curr.c = c, curr.d = d;
        }
    }
    printf("%lld\n", count);
}
