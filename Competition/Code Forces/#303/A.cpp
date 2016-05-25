#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    int m[107][107],ans[107];
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&m[i][j]);
            if(m[i][j]==1){
                ans[i]=1;
                //cout<<i<<endl;
            }
            else if(m[i][j]==2){
                ans[j]=1;
                //cout<<j<<endl;
            }
            else if(m[i][j]==3){
                ans[i]=1;
                ans[j]=1;
            }
        }
    }
    int num=0;
    for(i=1;i<=n;i++){
        if(!ans[i]){
            num++;
        }
    }
    if(num==0){
        printf("0\n");
    }
    else{
        printf("%d\n",num);
        int p=0;
        for(i=1;i<=n;i++){
            if(!ans[i]&&p==0){
                p=1;
                printf("%d",i);
            }
            else if(!ans[i]&&p==1){
                printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
