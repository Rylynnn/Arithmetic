#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[10000];
int dp[100000];
int main()
{
    int n,i,num,m,value,j,k,sum;
    int q,p;
    v[1000000]=1;
    while(~scanf("%d",&n)&&n>0){//waµã£ºÌõ¼þ²»¶Ô(Ö®Ç°ÒòÎªÑùÀýÐ´µÄ²»µÈÓÚ-1.¡£¡£¡£=-=wa4·¢¡£¡£orz)
        i=1;
        num=0;
        sum=0;
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
        while(n--){
            scanf("%d%d",&value,&m);
            num+=m;
            while(m--){
                v[i++]=value;
                sum+=value;
                //printf("%d\n",v[i-1]);
            }
            //printf("%d\n",num);
        }
        for(j=1;j<=num;j++){//×îºóÒ»¸öi»áÔÙ¼ÓÒ»´Î=-=
            for(k=sum/2;k>=v[j];k--){
                dp[k]=max(dp[k],dp[k-v[j]]+v[j]);//01±³°ü´ÓÒ»°ë¿ªÊ¼×°
                //printf("%d\n",dp[k]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
}
