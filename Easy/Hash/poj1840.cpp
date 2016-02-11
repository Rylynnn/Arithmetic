#include <cstdio>
#include <cstring>
short ha[25000005];//调不出来了两个小时。。。因为范围弄错了日。。。首先是50的4次方，然后乘以二，然后正负乘以二
int main()
{
    int a1,a2,a3,a4,a5,i,j,k,sum,ans;
    scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    memset(ha,0,sizeof(ha));
    for(i=-50;i<=50;i++){
        sum=0;
        if(!i){
            continue;
        }
        for(j=-50;j<=50;j++){
            if(!j){
                continue;
            }
            sum=a1*i*i*i+a2*j*j*j;
            //printf("%d %d %d %d %d",a1,a2,i,j,sum);
            if(sum<0){
                sum=25000000+sum;
            }
            ha[sum]++;
        }
    }
    ans=0;
    for(i=-50;i<=50;i++){
        sum=0;
        if(!i){
            continue;
        }
        for(j=-50;j<=50;j++){
            if(!j){
                continue;
            }
            for(k=-50;k<=50;k++){
                if(!k){
                    continue;
                }
                sum=-1*(a5*k*k*k+a4*j*j*j+a3*i*i*i);
                //printf("%d ",sum);
                if(sum<0){
                    sum=25000000+sum;
                }
                ans+=ha[sum];
            }
        }
    }
    printf("%d\n",ans);
}
