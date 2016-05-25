#include <cstdio>
using namespace std;
int main()
{
    int t,now;
    double a,sum;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            sum=0;
            for(int i=1;i<=12;i++){
                scanf("%lf",&a);
                sum+=a;
            }
            //cout<<sum;
            sum=sum/12;
            now=sum*1000000000;
            if(now%100000000==0){
                if(now%1000000000==0){
                    printf("$%d\n",now/1000000000);
                }
                else{
                    printf("$%.1f\n",sum);
                }
            }
            else{
                printf("$%.2f\n",sum);
            }

        }
    }
    return 0;
}
