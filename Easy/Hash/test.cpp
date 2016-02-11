#include <stdio.h>
#include <string.h>

short hash[25000001];

int main()
{
    int a1,a2,a3,a4,a5,x1,x2,x3,x4,x5,sum;

    while(~scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5))
    {
        memset(hash,0,sizeof(hash));
        for(x1 = -5; x1<=5; x1++)
        {
            if(!x1)
                continue;
            for(x2 = -5; x2<=5; x2++)
            {
                if(!x2)
                    continue;
                sum = -1*(a1*x1*x1*x1+a2*x2*x2*x2);
                //printf("%d ",sum);
                if(sum<0)
                    sum+=25000000;//数字下标没有负数，换一种出储存方式
                hash[sum]++;
            }
        }
        int cnt = 0;
        for(x3 = -5; x3<=5; x3++)
        {
            if(!x3)
                continue;
            for(x4 = -5; x4<=5; x4++)
            {
                if(!x4)
                    continue;
                for(x5 = -5; x5<=5; x5++)
                {
                    if(!x5)
                        continue;
                    sum = a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;
                    printf("%d ",sum);
                    if(sum<0)
                        sum+=25000000;
                    cnt+=hash[sum];
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
