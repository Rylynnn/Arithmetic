#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,i,j,c[107],sum,x,y,inter,beg,p;
    memset(c,0,sizeof(c));
    while(scanf("%d",&m)!=EOF){
        p=0;
        sum=0;
        for(i=1;i<=m;i++){
            scanf("%d",&c[i]);
            sum+=c[i];
        }
        //cout<<sum<<endl;
        scanf("%d%d",&x,&y);
        for(i=1;i<=m;i++){
            beg=0;
            inter=0;
            //printf("%d %d\n",beg,inter);
            for(j=1;j<i;j++){
                beg+=c[j];
            }
            inter=sum-beg;
            //printf("%d %d\n",beg,inter);
            if(p==0&&beg>=x&&beg<=y&&inter>=x&&inter<=y){
                p=1;
                printf("%d\n",i);
            }
        }
        if(p==0){
        printf("0\n");
    }
    }
    return 0;
}
