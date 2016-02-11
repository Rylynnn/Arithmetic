# include<stdio.h>
int main()
{
    int t,i,sum,j,k,m,n,q,a,b,c,d,x1,x2,y1,y2,cnt;
    int p[505][505];
    while(scanf("%d",&t)){
        while(t--){
            scanf("%d%d%d",&n,&m,&q);
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    scanf("%d",&a);
                    p[i][j]=a-1;
                }
            }
            for(i=0;i<q;i++){
                scanf("%d",&a);
                if(a==1){
                    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                    cnt=0;
                    sum=0;
                    for(j=x1;j<=x2;j++){
                        for(k=y1;k<=y2;k++){
                            sum^= p[j][k];
                        }
                    }
                    for(j=x1;j<=x2;j++){
                        for(k=y1;k<=y2;k++){
                             if(p[j][k]>(sum^p[j][k]))
                                cnt++;
                        }
                    }
                    if(cnt!=0){
                        printf("Yes\n");
                    }
                    else{
                        printf("No\n");
                    }
                }
                if(a==2){
                    scanf("%d%d%d",&b,&c,&d);
                    p[b][c]=d-1;
                }
            }
        }
    }
    return 0;
}
