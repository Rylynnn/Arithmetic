#include<cstdio>
int a[]
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                if(n%2||m%2){
                    sum+=a[i][j];
                }
            }
        }
        if(n%2||m%2){
            printf("%d\n",sum);
            if(n%2){
                for(i=1;i<=n;i++)}{
                    for(j=1;j<m-1;j++){
                        if(i%2){
                            printf("R");
                        }
                        else{
                            printf("L");
                        }
                    }
                    printf("D\n");
                }
            }
            else if(m%2){
                for(i=1;i<=m;i++)}{
                    for(j=1;j<n-1;j++){
                        if(i%2){
                            printf("D");
                        }
                        else{
                            printf("U");
                        }
                    }
                    printf("R\n");
                }
            }
        }
    }
}
