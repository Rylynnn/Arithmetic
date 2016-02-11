#include<cstdio>
#include<cstring>
#define INF 1000000007
long long b[110],c[110];
long long a[110][110];
long long quickpow(long long m,long long n,long long k)
{
    long long b=1;
    while(n>0){
          if(n&1)
             b=(b*m)%k;
          n =n>>1 ;
          m =(m*m)%k;
    }
    return b;
}
long long quickfac(long long n){
    long long sum=1;
    while(n>=1){
        sum=(sum*n)%INF;
        n--;
    }
    return sum;
}
bool judge(long long n,long long m){
    long long i,j,x;
    for(i=1;i<=n;i++){
        x=i;
        for(j=m;j>=1;j--){
            x=a[j][x];
            //printf("%I64d ",x);
        }
        if(x!=i){
            return false;
        }
    }
    return true;
}
int main()
{
    long long n,m,i,fi;
    //freopen("data.txt","w",stdout);
    for(i=1;i<=100;i++){
        c[i]=quickfac(i);//wa前后都有b[]....
        //printf("%d ",c[i]);
    }
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        long long fi=0;
        long long num=0;
        long long k;
        for(k=1;k<=m;k++){
            memset(b,0,sizeof(b));
            for(i=1;i<=n;i++){
                scanf("%I64d",&a[k][i]);
                //printf("%I64d ",a[k][i]);
                if(a[k][i]==-1){
                    num++;
                    //p=1;
                    //printf("%I64d ",num);
                    break;
                }
                if(!b[a[k][i]]){
                    b[a[k][i]]=1;
                }
                else{
                    fi=1;//判函数可用性
                    //printf("1\n");
                    //break;//不能再这里break！！！不然没有办法完全读入所有数据
                }
                //printf("%I64d ",a);
            }
            /*if(fi){
                break;
            }*/
        }
        if(fi||(!num&&!judge(n,m))){
            printf("0\n");
        }
        else{
            printf("%I64d\n",quickpow(c[3],num-1,INF));
        }
    }
}
