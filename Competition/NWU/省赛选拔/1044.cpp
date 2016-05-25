#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct card{
    int a,b,c;
};
int vis[1000];
card bao[9],shun[8],dui[100],dan[1000];
int judge(card x){
    if(x.a==x.b&&x.b==x.c){
        return 1;
    }
    else if(x.a==x.b||x.a==x.c||x.b==x.c){
        return 3;
    }
    else if(x.a!=x.b&&x.a!=x.c&&x.b!=x.c){
        if((x.a+1==x.b)&&(x.b+1==x.c)){
            return 2;
        }
        else{
            return 4;
        }
    }
}
int main(){
    //freopen("out.txt","w",stdout);
    int t,type,num,nnum,ans;
    card bad;
    for(int i=1;i<=9;i++){
        bao[i].a=bao[i].b=bao[i].c=i;
    }
    for(int i=1;i<=7;i++){
        shun[i].a=i;
        shun[i].b=i+1;
        shun[i].c=i+2;
    }
    num=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i!=j){
                dui[++num].a=dui[num].b=i;
                dui[num].c=j;
            }
        }
    }
    //cout<<num;
    nnum=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                if(i!=j&&i!=k&&j!=k){
                    int p[3];
                    p[0]=i,p[1]=j,p[2]=k;
                    sort(p,p+3);
                    int now;
                    now=p[0]+p[1]*10+p[2]*100;
                    if(vis[now]==0){
                        vis[now]=1;
                        if(p[0]+1!=p[1]||p[1]+1!=p[2]){
                            dan[++nnum].a=p[0];
                            dan[nnum].b=p[1];
                            dan[nnum].c=p[2];
                            //
                        }
                    }
                }
            }
        }
    }

    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d%d",&bad.a,&bad.b,&bad.c);
            int p[3];
            p[0]=bad.a,p[1]=bad.b,p[2]=bad.c;
            sort(p,p+3);
            //cout<<p[0]<<p[1]<<p[2];
            bad.a=p[0],bad.b=p[1],bad.c=p[2];
            type=judge(bad);
            //cout<<type;
            if(type==1){
                printf("%d\n",9-bad.a+1);
            }
            else if(type==2){
                printf("%d\n",9+7-bad.a);
            }
            else if(type==3){
                int tt;
                if(bad.a!=bad.b){
                    tt=bad.c;
                    bad.c=bad.a;
                    bad.a=tt;
                }
                ans=0;
                for(int i=1;i<=num;i++){
                    if(dui[i].a>bad.a){
                        ans++;
                    }
                    else if(dui[i].a==bad.a){
                        if(dui[i].c>bad.c){
                            ans++;
                        }
                    }
                }
                printf("%d\n",ans+9+7);
            }
            else if(type==4){
                ans=0;
                for(int i=1;i<=nnum;i++){
                    if(dan[i].c>bad.c){
                        ans++;
                        //cout<<dan[i].a<<' '<<dan[i].b<<' '<<dan[i].c<<endl;
                    }
                    else if(dan[i].c==bad.c){
                        if(dan[i].b>bad.b){
                            ans++;
                            //cout<<dan[i].a<<' '<<dan[i].b<<' '<<dan[i].c<<endl;
                        }
                        else if(dan[i].b==bad.b){
                            if(dan[i].a>bad.a){
                                ans++;
                                //cout<<dan[i].a<<' '<<dan[i].b<<' '<<dan[i].c<<endl;
                            }
                        }
                    }

                }
                if(bad.a==2&&bad.b==3&&bad.c==5){
                    printf("%d\n",num+7+ans);
                }
                else{
                    printf("%d\n",9+7+num+ans);
                }
            }
        }
    }
}
