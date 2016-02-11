#include <cstdio>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#define N 400010
using namespace std;
int cant[10]={1,1,2,6,24,120,720,5040,40320,362880};
int m[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//udlr
int vis[N];
string pa;
string p="udlr";
struct node{
    int s[9];
    int loc;
    int can;
    string path;
}eight,now;
queue <node>q;
int cantor(int a[]){//康拓展开求hash值
    int i,j,sum=0,num;
    for(i=0;i<9;i++){
        num=0;
        for(j=i+1;j<9;j++){
            if(a[j]<a[i]){
                ++num;
            }
        }
        sum+=num*cant[9-i-1];
    }
    return sum+1;
}
void init(){
    int i;
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof(vis));
}
bool bfs(){
    init();
    q.push(eight);
    node a,next;
    int x,y,xx,yy,i;
    while(!q.empty()){
        a=q.front();
        q.pop();//记得要出队列。
        if(a.can==46234){
            pa=a.path;
            return true;
        }
        x=a.loc/3;
        y=a.loc%3;
        //printf("%d%d ",x,y);
        for(i=0;i<4;i++){
            xx=x+m[i][0];
            yy=y+m[i][1];
            //printf("%d%d",xx,yy);
            if(xx<0||yy<0||xx>2||yy>2){
                continue;
            }
            next=a;
            next.loc=xx*3+yy;
            next.s[a.loc]=a.s[next.loc];
            next.s[next.loc]=0;
            next.can=cantor(next.s);
            if(!vis[next.can]){
                vis[next.can]=1;
                next.path+=p[i];
                //cout<<next.path<<endl;
                //printf("%d ",next.can);
                if(a.can==46234){
                    pa=a.path;
                    return true;
                }
                q.push(next);
            }
        }
    }
}
int main(){
    int i;
    char a;
    for(i=0;i<9;i++){
        cin>>a;
        if(a=='x'){
            eight.s[i]=0;
            eight.loc=i;
        }
        else{
            eight.s[i]=a-'0';
        }
        //printf("%d",eight.s[i]);
    }
    eight.can=cantor(eight.s);
    //printf("%d",eight.can);
    if(bfs()){
        cout<<pa<<endl;
    }
    else{
        cout<<"unsolvable"<<endl;
    }
    return 0;
}
