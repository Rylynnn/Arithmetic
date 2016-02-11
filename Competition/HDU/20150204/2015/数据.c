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
            printf("%d\n",Random(15,99));
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
