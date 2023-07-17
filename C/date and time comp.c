#include <stdio.h>

typedef struct dateTime
{
    int year, month, day, hour, min, sec;
} dt;

int comp(dt m1, dt m2)
{
    if(m1.year < m2.year)
    {
        return 1;
    }
    if(m1.year > m2.year)
    {
        return -1;
    }
    if(m1.month < m2.month)
    {
        return 1;
    }
    if(m1.month > m2.month)
    {
        return -1;
    }
    if(m1.day < m2.day)
    {
        return 1;
    }
    if(m1.day > m2.day)
    {
        return -1;
    }
    if(m1.hour < m2.hour)
    {
        return 1;
    }
    if(m1.hour > m2.hour)
    {
        return -1;
    }
    if(m1.min < m2.min)
    {
        return 1;
    }
    if(m1.min > m2.min)
    {
        return -1;
    }

    if(m1.sec < m2.sec)
    {
        return 1;
    }
    if(m1.sec > m2.sec)
    {
        return -1;
    }
    return 0;
}
int main()
{
    dt s1 = {2020, 05, 12, 5, 34, 20};
    dt s2 = {2020, 05, 12, 5, 34, 20};
    int val = comp(s1, s2);
    printf("The function returns %d\n",val);
    return 0;
}
