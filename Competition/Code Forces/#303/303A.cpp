#include<cstdio>
#include<cstring>
int main()
{
    int n,i,j;
    int a[110][110],p[110];
    scanf("%d",&n);
    memset(p,0,sizeof(p));
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1){
                p[i]=1;
            }
            else if(a[i][j]==2){
                p[j]=1;
            }
            else if(a[i][j]==3){
                p[i]=1;
                p[j]=1;
            }
        }
    }
    int sum=0;
    for(i=1;i<=n;i++){
        if(p[i]==0){
            sum++;
        }
    }
    int po=0;
    printf("%d\n",sum);
    if(sum!=0){
        for(i=1;i<=n;i++){
            if(p[i]==0){
                if(po==0){
                    printf("%d",i);
                    po=1;
                }
                else printf(" %d",i);
            }
        }
    }
    return 0;
}
