#include <cstdio>
#include <cstring>
int main()
{
    int t,d[10],b[10][10],now[10][2];
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            memset(d,0,sizeof(d));
            memset(b,0,sizeof(b));
            memset(now,0,sizeof(now));
            for(int i=1; i<=5; i++)
            {
                scanf("%d%d%d%d%d",&d[i],&b[1][i],&b[2][i],&b[3][i],&b[4][i]);
            }
            if(d[1]==1||d[1]==2)
            {
                now[1][0]=2;
                now[1][1]=b[2][1];
                printf("2 %d\n",b[2][1]);
            }
            else if(d[1]==3)
            {

                now[1][0]=3;
                now[1][1]=b[3][1];
                printf("3 %d\n",b[3][1]);
            }
            else if(d[1]==4)
            {
                now[1][0]=4;
                now[1][1]=b[4][1];
                printf("4 %d\n",b[4][1]);
            }


            if(d[2]==1)
            {
                for(int j=1; j<=4; j++)
                {
                    if(b[j][2]==4)
                    {
                        now[2][0]=j;
                        now[2][1]=4;
                        printf("%d 4\n",j);
                        break;
                    }
                }
            }
            else if(d[2]==2)
            {
                for(int j=1; j<=4; j++)
                {
                    if(j==now[1][0])
                    {
                        now[2][0]=j;
                        now[2][1]=b[j][2];
                        printf("%d %d\n",j,b[j][2]);
                        break;
                    }
                }
            }
            else if(d[2]==3)
            {
                now[2][0]=1;
                now[2][1]=b[1][2];
                printf("1 %d\n",b[1][2]);
            }
            else if(d[2]==4)
            {
                for(int j=1; j<=4; j++)
                {
                    if(j==now[1][0])
                    {
                        now[2][0]=j;
                        now[2][1]=b[j][2];
                        printf("%d %d\n",j,b[j][2]);
                        break;
                    }
                }
            }


            if(d[3]==1){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][3]==now[2][1])
                    {
                        now[3][0]=j;
                        now[3][1]=b[j][3];
                        printf("%d %d\n",j,b[j][3]);
                        break;
                    }
                }
            }
            else if(d[3]==2){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][3]==now[1][1])
                    {
                        now[3][0]=j;
                        now[3][1]=b[j][3];
                        printf("%d %d\n",j,b[j][3]);
                        break;
                    }
                }
            }
            else if(d[3]==3){
                now[3][0]=3;
                now[3][1]=b[3][3];
                printf("3 %d\n",b[3][3]);
            }
            else if(d[3]==4){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][3]==4)
                    {
                        now[3][0]=j;
                        now[3][1]=4;
                        printf("%d 4\n",j);
                        break;
                    }
                }
            }


            if(d[4]==1){
                for(int j=1; j<=4; j++)
                {
                    if(j==now[1][0])
                    {
                        now[4][0]=j;
                        now[4][1]=b[j][4];
                        printf("%d %d\n",j,b[j][4]);
                        break;
                    }
                }
            }
            else if(d[4]==2){
                now[4][0]=1;
                now[4][0]=b[1][4];
                printf("1 %d\n",b[1][4]);
            }
            else if(d[4]==3){
                for(int j=1; j<=4; j++)
                {
                    if(j==now[2][0])
                    {
                        now[4][0]=j;
                        now[4][1]=b[j][4];
                        printf("%d %d\n",j,b[j][4]);
                        break;
                    }
                }
            }
            else if(d[4]==4){
                for(int j=1; j<=4; j++)
                {
                    if(j==now[2][0])
                    {
                        now[4][0]=j;
                        now[4][1]=b[j][4];
                        printf("%d %d\n",j,b[j][4]);
                        break;
                    }
                }
            }


            if(d[5]==1){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][5]==now[1][1])
                    {
                        now[5][0]=j;
                        now[5][1]=b[j][5];
                        printf("%d %d\n",j,b[j][5]);
                        break;
                    }
                }
            }
            else if(d[5]==2){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][5]==now[2][1])
                    {
                        now[5][0]=j;
                        now[5][1]=b[j][5];
                        printf("%d %d\n",j,b[j][5]);
                        break;
                    }
                }
            }
            else if(d[5]==3){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][5]==now[4][1])
                    {
                        now[5][0]=j;
                        now[5][1]=b[j][5];
                        printf("%d %d\n",j,b[j][5]);
                        break;
                    }
                }
            }
            else if(d[5]==4){
                for(int j=1; j<=4; j++)
                {
                    if(b[j][5]==now[3][1])
                    {
                        now[5][0]=j;
                        now[5][1]=b[j][5];
                        printf("%d %d\n",j,b[j][5]);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
