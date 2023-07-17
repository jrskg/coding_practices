#include <stdio.h>

typedef struct suraj {
    int x;
    int y;
} MS;

MS suraj(MS a, MS b)
{
    MS result;
    result.x = a.x + a.y;
    result.y = b.x + b.y;
    return result;
}

int main()
{
    MS m, s, sum;
    m.x = 5;
    m.y = 5;
    s.x = 6;
    s.y = 6;

    sum = suraj(m, s);

    printf("The sum of m is %d and the s is %d",sum.x, sum.y);

    return 0;
}
