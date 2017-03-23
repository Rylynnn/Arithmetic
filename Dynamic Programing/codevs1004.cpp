#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct node{
    string a[4];
}b;
queue<node> q;
int step;
bool judge(node t){
    for(int i=0;i<4;i++){
        if(t.a[i]=="BBBB"||t.a[i]=="WWWW"){
            return true;
        }
    }
    for(int i=0;i<4;i++){
        if(t.a[0][i]==t.a[1][i]&&t.a[1][i]==t.a[2][i]&&t.a[2][i]==t.a[3][i]){
            return true;
        }
    }
    int p=0;
    for(int i=0;i<4;i++){
        if(t.a[i][i]!=t.a[0][0]){
            p=1;
        }
    }
    if(p==0){
        return true;
    }
    p=0;
    for(int i=0;i<4;i++){
        if(t.a[i][3-i]!=t.a[0][3]){
            p=1;
        }
    }
    if(p==0){
        return true;
    }
    return false;
}
void bfs(){
    node tmp;
    int now;
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        now=judge(tmp);
        if(now==true){
            break;
        }
        step++;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tmp.a[i][j]=='O'){
                    b=tmp;
                    if(i-1>=0){
                        swap(b.a[i][j],b.a[i-1][j]);
                        q.push(b);
                    }
                    b=tmp;
                    if(j-1>=0){
                        swap(b.a[i][j],b.a[i][j-1]);
                        q.push(b);
                    }
                    b=tmp;
                    if(i+1<4){
                        swap(b.a[i][j],b.a[i+1][j]);
                        q.push(b);
                    }
                    b=tmp;
                    if(j+1<4){
                        swap(b.a[i][j],b.a[i][j+1]);
                        q.push(b);
                    }
                }
            }
        }
    }
}
int main()
{
    node m;
    step=0;
    q.empty();
    for(int i=0;i<4;i++){
        cin>>m.a[i];
    }
    printf("%d ",judge(m));
    q.push(m);
    bfs();
    printf("%d\n",step);
}

