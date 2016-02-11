#include <cstdio>
int main()
{
    int x,y,w,n;
    int i,num,t,b,a;
    while(scanf("%d%d%d%d",&x,&y,&w,&n)!=EOF){
        if(x<w){
            printf("%d\n",(n-1)*(x+y));
        }
        else{
            num=1;
            t=0;
            num+=(x-x%w)/w;
            b=(n-n%num)/num;
            a=n%num;
            if(a>0){
                t+=b*(x+y)+(a-1)*w;
            }
            else{
                t+=(b-1)*(x+y)+(num-1)*w;
            }
            printf("%d\n",t);
        }
    }
    return 0;
}
