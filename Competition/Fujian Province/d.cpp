#include <iostream>
#include<cstdio>
#include<cstring>
int accelerated[101];
int speed[101];
long long lenght[101];
int main()
{

    int n,m,t;
    memset(lenght, 0, sizeof(lenght));
    memset(speed, 0, sizeof(speed));
    std::cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
    {
        std::cin>>accelerated[i];
    }
    int flag = m*t;
    for(int j=1;j<=n;j++)
    {
        speed[j] += accelerated[j];
    }
    for(int i=1;i<=flag;i++)
    {
        for(int j=1;j<=n;j++)
        {
            lenght[j] += speed[j];
            speed[j] += accelerated[j];
        }
        if(!(i%t))
        {
            int tag=1;
            for(int j =1;j<=n;j++)
            {
                if(lenght[j]>lenght[tag])
                    tag = j;
            }
            speed[tag] = 0;
            if(i==m*t)
                printf("%d\n",tag);
            else
                printf("%d ",tag);
        }
    }
}
