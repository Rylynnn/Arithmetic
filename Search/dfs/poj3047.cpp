/*
wa:所有数组统一下标，要么全从0开始，要么全从1开始。
*/
#include<cstdio>
#include<cstring>
#incldue<queue>
using namespace std;
int r[10][10];
int c[10][10];
int number[10][10];
int b[4][4][10];
struct node{
    int x,y;
}block[100];
struct sum{
    int a;
    int b;
};
bool dfs(int n){
    int i,j,k;
    if(n==0){
        return true;
    }
    int x=block[n].x;
    int y=block[n].y;
    for(i=1;i<=9;i++){
        if(r[x][i]!=1&&c[y][i]!=1&&b[x/3][y/3][i]!=1){
            r[x][i]=1;
            c[y][i]=1;
            b[x/3][y/3][i]=1;
            number[x][y]=i;
            if(dfs(n-1)){
                /*for(k=0;k<9;k++){
                    for(j=0;j<9;j++){
                        printf("%d",number[k][j]);
                    }
                    printf("\n");
                }*/
                return true;
            }
            r[x][i]=0;
            c[y][i]=0;
            b[x/3][y/3][i]=0;
        }
    }
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,num,t,a,n;
    scanf("%d",&t);
    priority_queue<sum,vector<sum>,greater<sum> >rn;
    priority_queue<sum,vector<sum>,greater<sum> >jn;
    priority_queue<sum,vector<sum>,greater<sum> >bn;
    while(t--){
        num=0;
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        memset(number,0,sizeof(number));
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                n=scanf("%1d",&a);//读入方法
                //printf("%d",a);
                number[i][j]=a;
                if(a!=0){
                    r[i][a]=1;
                    c[j][a]=1;
                    b[i/3][j/3][a]=1;
                }
                else if(n==0){
                    block[++num].x=i;
                    block[num].y=j;

                    //printf("%d %d %d\n",i,j,a);
                }
            }
        }
        //printf("%d\n",num);
        dfs(num);
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                printf("%d",number[i][j]);
            }
            printf("\n");
        }
    }
}
