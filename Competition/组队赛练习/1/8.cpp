#include <cstdio>
using namespace std;
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int p=0;
        long long sum=0;
        m+=1;
        while(n--){
            if(p==0){
                sum+=--m;
                p=1;
            }
            else if(p==1){
                sum+=m;
                p=0;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
