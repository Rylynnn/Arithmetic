#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    queue<int>k1;
    queue<int>k2;
    int i,t,a,b,num1,num2,num=0;
    int n1[11],n2[11];
    scanf("%d",&t);
    scanf("%d",&num1);
    for(i=1;i<=num1;i++){
        scanf("%d",&a);
        n1[i]=a;
        k1.push(a);
    }
    scanf("%d",&num2);
    for(i=1;i<=num2;i++){
        scanf("%d",&b);
        n2[i]=b;
        k2.push(b);
    }
    int p=0;
    while(!k1.empty()&&!k2.empty()){
        if(k1.front()>k2.front()){
            a=k2.front();
            b=k1.front();
            k1.push(a);
            k1.push(b);
            k1.pop();
            k2.pop();
            //printf("1:%d%d\n",a,b);
        }
        else if(k1.front()<k2.front()){
            a=k1.front();
            b=k2.front();
            k2.push(a);
            k2.push(b);
            k1.pop();
            k2.pop();
            //printf("2:%d%d\n",a,b);
        }
        num++;
        int point=0;
        if(k1.size()==num1&&k2.size()==num2&&k1.front()==n1[1]&&k2.front()==n2[1]){
        for(i=1;i<=num1;i++){
            if(point==1){
                k1.push(a);
            }
            if(k1.front()==n1[i]){
                a=k1.front();
                k1.pop();
                point=1;
            }
            else{
                break;
            }
        }
        if(i-1==num1){
            p=1;
            break;
        }
        point=0;
        for(i=1;i<=num1;i++){
            if(point==1){
                k1.push(a);
            }
            if(k2.front()==n2[i]){
                a=k2.front();
                k2.pop();
                point=1;
            }
            else{
                break;
            }
        }
        if(i-1==num2){
            p=1;
            break;
        }
        }
    }
    if(p==0){
        printf("%d ",num);
        if(k2.empty()){
            printf("1");
        }
        else{
            printf("2");
        }
    }
    else if(p==1){
        printf("-1");
    }
    return 0;
}
