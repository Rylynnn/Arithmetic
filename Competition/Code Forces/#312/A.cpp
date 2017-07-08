#include <bits/stdc++.h>
using namespace std;
priority_queue
int main()
{
    int n;
    int a[5007];
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            printf("1\n1\n");
        }
        else if(n==2){
            printf("1\n1\n");
        }
        else if(n==3){
            printf("2\n1 3\n");
        }
        else if(n==4){
            printf("4\n3 1 4 2\n");
        }
        else if(n%2==1){
            for(int i=1;i<=n/2+1;i++){
                a[(i-1)*2+1]=i;
            }
            int num=1;
            for(int i=n/2+2;i<=n;i++){
                a[num*2]=i;
                num++;
            }
            printf("%d\n%d",n,a[1]);
            for(int i=2;i<=n;i++){
                printf(" %d",a[i]);
            }
            printf("\n");
        }
        else if(n%2==0){
            for(int i=1;i<=n/2;i++){
                a[(i-1)*2+1]=i;
            }
            int num=1;
            for(int i=n/2+1;i<=n;i++){
                a[num*2]=i;
                num++;
            }
            printf("%d\n%d",n,a[1]);
            for(int i=2;i<=n;i++){
                printf(" %d",a[i]);
            }
            printf("\n");
        }
    }
}
