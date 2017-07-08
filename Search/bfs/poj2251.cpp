#include <cstdio>
#include <string>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int l,r,c;
int result;
string a[37][37];
int vis[37][37][37];
int tx[6]={1,0,-1,0,0,0};
int ty[6]={0,0,0,0,1,-1};
int tz[6]={0,1,0,-1,0,0};
struct node{
    int x,y,z,s;
    node(){};
    node(int xx, int yy, int zz, int ss):x(xx),y(yy),z(zz),s(ss){}
};
queue<node> q;
int bfs(){
    node tmp;
    while(!q.empty()){
        tmp=q.front();
        q.pop();//cout<<tmp.x<<' '<<tmp.y<<' '<<tmp.z<<endl;
        for(int i=0;i<6;i++){
            int nx=tmp.x+tx[i];
            int ny=tmp.y+ty[i];
            int nz=tmp.z+tz[i];
            if(nx>=0&&nx<l&&ny>=0&&ny<r&&nz>=0&&nz<c){
                if(a[nx][ny][nz]=='.'){
                    a[nx][ny][nz]='#';
                    //cout<<nx<<' '<<ny<<' '<<nz<<' '<<tmp.s+1<<endl;
                    q.push(node(nx,ny,nz,tmp.s+1));
                }
                if(a[nx][ny][nz]=='E'){
                    //cout<<tmp.s+1<<endl;
                    return tmp.s+1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d%d",&l,&r,&c)!=EOF){
        if(l==0&&r==0&&c==0){
            break;
        }
        while(!q.empty()){
            q.pop();
        }
        int p=0;
        for(int i=0;i<l;i++){
            for(int j=r-1;j>=0;j--){
                cin>>a[i][j];
                if(p==0){
                    for(int k=0;k<c;k++){
                        //cout<<a[i][j][k];
                        if(a[i][j][k]=='S'){
                            p=1;
                            q.push(node(i,j,k,0));
                        }
                    }//cout<<endl;
                }
            }
        }
        result=bfs();
        if(result==-1){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",result);
        }
    }
    return 0;
}
