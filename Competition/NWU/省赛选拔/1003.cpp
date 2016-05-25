#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int x,y;
}be[10];
int t,a[10][10],vis[1007],p;
int main()
{
    be[1].x=be[2].x=be[3].x=1;
    be[4].x=be[5].x=be[6].x=4;
    be[7].x=be[8].x=be[9].x=7;
    be[1].y=be[4].y=be[7].y=1;
    be[2].y=be[5].y=be[8].y=4;
    be[3].y=be[6].y=be[9].y=7;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            for(int i=1;i<=9;i++){
                for(int j=1;j<=9;j++){
                    scanf("%d",&a[i][j]);
                }
            }
            p=0;
            for(int i=1;i<=9;i++){
                memset(vis,0,sizeof(vis));
                for(int j=1;j<=9;j++){
                    if(vis[a[i][j]]==0)
                        vis[a[i][j]]=1;
                }
                for(int k=1;k<=9;k++){
                    if(vis[k]==0){
                        p=1;
                    }
                }
            }
            //cout<<p;
            for(int i=1;i<=9;i++){
                memset(vis,0,sizeof(vis));
                for(int j=1;j<=9;j++){
                    if(vis[a[j][i]]==0)
                        vis[a[j][i]]=1;
                }
                for(int k=1;k<=9;k++){
                    if(vis[k]==0){
                        p=1;
                    }
                }
            }
            //cout<<p;
            int x,y;
            for(int i=1;i<=9;i++){
                memset(vis,0,sizeof(vis));
                x=be[i].x;
                y=be[i].y;
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        if(vis[a[x+j][y+k]]==0){
                            vis[a[x+j][y+k]]=1;
                        }
                    }
                }
                for(int k=1;k<=9;k++){
                    if(vis[k]==0){
                        p=1;
                    }
                }
            }
            //cout<<p;
            if(p==0){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }

}
