#include <bits/stdc++.h>
using namespace std;
int m[107][107];
int n;
void doit(int a,int b,int c,int d){
    for(int i=100-a+1;i>=100-c+1;i--){
        for(int j=b;j<=d;j++){
            m[i][j]+=1;
        }
    }
}
int main()
{
    scanf("%d",&n);
    int sum=0,x1,x2,y1,y2;
    memset(m,0,sizeof(m));
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        doit(x1,y1,x2,y2);
    }
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            sum+=m[i][j];
        }
    }
    printf("%d\n",sum);
}
