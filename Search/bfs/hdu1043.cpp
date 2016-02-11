#include <cstdio>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#define N 370010
using namespace std;
int cant[10]={1,1,2,6,24,120,720,5040,40320,362880};
int m[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//udlr
int vis[N];
string path[N];
string p="durl";
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
    for(i=0;i<8;i++){
        now.s[i]=i+1;
        //printf("%d",now.s[i]);
    }//最后一个序列
    now.s[8]=0;
    now.can=46234;
    //printf("%d",cantor(now.s));
    now.loc=8;
    now.path="";
    path[46234]="";
}
void bfs(){
    init();
    q.push(now);
    node a,next;
    int x,y,xx,yy,i;
    while(!q.empty()){
        a=q.front();
        q.pop();//记得要出队列。
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
                next.path=p[i]+next.path;//倒着搜，从后面加
                //cout<<next.path<<endl;
                //printf("%d ",next.can);
                q.push(next);
                path[next.can]=next.path;
            }
        }
    }
}
int main(){
    int i;
    char a;
    bfs();
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
    if(vis[eight.can]){
        cout<<path[eight.can]<<endl;
    }
    else{
        cout<<"unsolvable"<<endl;
    }
    return 0;
}
