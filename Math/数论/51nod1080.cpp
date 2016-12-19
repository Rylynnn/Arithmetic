#include <bits/stdc++.h>
using namespace std;
map<int,int> q;
int main()
{
    int n,num;
    while(scanf("%d",&n)!=EOF){
        q.clear();
        int p=0;
        for(int i=0;i*i<=n;i++){
            if(((int)(sqrt(n-i*i)*(int)sqrt(n-i*i))==n-i*i)){
                num=sqrt(n-i*i);
                if(q[i]!=1){
                    p=1;
                    printf("%d %d\n",i,num);
                    q[num]=1;
                }
            }
        }
        if(p==0){
            printf("No Solution\n");
        }
    }
}
