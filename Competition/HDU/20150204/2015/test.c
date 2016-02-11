#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random(int m, int n)
{
        int pos, dis;
        if(m == n)
        {
            return m;
        }
        else if(m > n)
        {
            pos = n;
            dis = m - n + 1;
            return rand() % dis + pos;
        }
        else
        {
            pos = m;
            dis = n - m + 1;
            return rand() % dis + pos;
        }
}
int main()
{
        int i, m, n;
        srand((int)time(NULL));
        m = 1;
        n = 11;
        for(i=0; i<10; i++)
        {
            printf("%d\n", Random(m, n));
        }
        return 0;
}

