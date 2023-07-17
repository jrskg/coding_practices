#include <iostream>
#include <math.h>
using namespace std;

class point
{
    int x, y;
    friend float distance(point s, point m);
public:
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};

float distance(point s, point m)
{
    int res;
    res = (m.x-s.x)*(m.x-s.x)+(m.y-s.y)*(m.y-s.y);
    return sqrt(res);
}

int main()
{
    point s(1, 0);
    point m(70, 0);

    float result = distance(s, m);
    cout<<"The distance is "<<result<<" cm"<<endl;

    return 0;
}
