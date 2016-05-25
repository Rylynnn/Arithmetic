#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll& x,ll& y) {
    if(b==0) {
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return;
}
int main() {
    ll a,b,c,x1,x2,y1,y2,x,y,t,num,k1,k2,k3,k4;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF) {
        scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&y1,&y2);
        if(a==0&&b==0) {
            if(c==0) {
                printf("%I64d\n",(x2-x1+1)*(y2-y1+1));
            }
            else {
                printf("0\n");
            }
        }
        else if(a==0&&b!=0) {
            if(c%b==0&&(c/b)>=y1&&(c/b)<=y2) {
                printf("%I64d\n",x2-x1+1);
            }
            else {
                printf("0\n");
            }
        }
        else if(b==0&&a!=0) {
            if(c%a==0&&(c/a)>=x1&&(c/a)<=x2) {
                printf("%I64d\n",y2-y1+1);
            }
            else {
                printf("0\n");
            }
        }
        else {
            t=gcd(a,b);
            c=-c;
            num=0;
            if(c%t!=0) {
                printf("0\n");
            }
            else {
                a/=t;
                b/=t;
                c/=t;
                exgcd(a,b,x,y);
                x*=c;
                y*=c;
                k1=(x1-x);
                k2=(x2-x);
                k3=(y-y1);
                k4=(y-y2);

                if(k1%b==0||k1<=0){
                    k1=k1/b;
                }
                else{
                    k1=k1/b+1;
                }
                if(k2%b==0||k2>=0){
                    k2=k2/b;
                }
                else{
                    k2=k2/b-1;
                }
                if(k3%a==0||k3>=0){
                    k3=k3/a;
                }
                else{
                    k3=k3/a-1;
                }
                if(k4%a==0||k4<=0){
                    k4=k4/a;
                }
                else{
                    k4=k4/a+1;
                }
                if(k2<=k1){
                    int temp=k1;
                    k1=k2;
                    k2=temp;
                }
                if(k4<=k3){
                    int temp=k3;
                    k3=k4;
                    k4=temp;
                }//cout<<k1<<' '<<k2<<' '<<k3<<' '<<k4<<' ';
                printf("%I64d\n",min(k4,k2)-max(k1,k3)+1);
            }
        }
    }
    return 0;
}
