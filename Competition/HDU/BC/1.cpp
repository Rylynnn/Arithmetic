#include <cstdio>
#include <cstring>
int main()
{
    int t,i,n,a,b,s[505],ans,num;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            memset(s,0,sizeof(s));
            for(i=1;i<=n;i++){
                scanf("%d%d",&a,&b);
                s[a]+=b;
            }
            num=0;
            ans=1;
            for(i=1;i<=500;i++){
                if(s[i]!=0){
                    if(num%64==0){
                        num+=s[i]/64;
                    }
                    else{
                        num+=s[i]/64+1;
                    }//printf("%d ",num);
                    //printf("%d ",ans);
                }
            }
            if(num%36==0){
                ans=num/36;
            }
            else{
                ans=num/36+1;
            }
            printf("%d\n",ans);
        }
    }
}
