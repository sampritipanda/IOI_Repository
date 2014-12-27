// Triangles Contain Origin

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
   float A = area (x1, y1, x2, y2, x3, y3);

   float A1 = area (x, y, x2, y2, x3, y3);
   float A2 = area (x1, y1, x, y, x3, y3);
   float A3 = area (x1, y1, x2, y2, x, y);

   return (A == A1 + A2 + A3);
}

class TrianglesContainOriginEasy {
    public:
    int count(vector <int> x, vector <int> y) {
      int N = x.size();
      int count = 0;
      for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
          for(int k = j + 1; k < N; k++){
            if(isInside(x[i], y[i], x[j], y[j], x[k], y[k], 0, 0)) count++;
          }
        }
      }

      return count;
    }
};
