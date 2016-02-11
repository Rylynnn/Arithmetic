#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LOCAL
int Random(int m,int n);
int main()
{
    #ifdef LOCAL
        freopen("data.in","w",stdout);
    #endif // LOCAL
    int m,n,num;
    int i,p;
    scanf("%d",&num);
    while(num>0){
            p=0;
            n=Random(1,100);
            printf("%d\n",n);
            for(i=1;i<=n;i++){
                if(p==0){printf("%d",Random(1,100));p=1;}
                else if(p==1)printf(" %d",Random(1,100));
            }
            printf("\n");
            p=0;
            m=Random(1,100);
            printf("%d\n",m);
            for(i=1;i<=m;i++){
                if(p==0){printf("%d",Random(1,100));p=1;}
                else if(p==1)printf(" %d",Random(1,100));
            }
            printf("\n");
            num--;
        }
    return 0;
}
int Random(int m, int n)
{
        int pos, dis;
        if(m == n){
            return m;
        }
        else if(m > n){
            pos = n;
            dis = m - n + 1;
            return rand() % dis + pos;
        }
        else{
            pos = m;
            dis = n - m + 1;
            return rand() % dis + pos;
        }
}
