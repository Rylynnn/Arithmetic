#include <cstdio>
int a[7]={0};
void prime(){
    int i,j,k,p,b,c,d,e,f,g,h,num;
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){//j满足的条件不能放在循环的第二个条件中！！
            if(j!=i)
            for(k=1;k<=4;k++){
                if(k!=j&&k!=i)
                for(p=1;p<=4;p++){
                    if(p!=k&&p!=j&&p!=i){
                        num=i*1000+j*100+k*10+p;
                        //printf("%d ",num);
                        if(num%7==0)a[0]=num;
                        if(num%7==1)a[1]=num;
                        if(num%7==2)a[2]=num;
                        if(num%7==3)a[3]=num;
                        if(num%7==4)a[4]=num;
                        if(num%7==5)a[5]=num;
                        if(num%7==6)a[6]=num;
                    }
                }
            }
        }
    }
    //for(i=0;i<=6;i++){
        //printf("%d ",a[i]);
    //}
}
int main()
{
    prime();
    int n,b;
    while(scanf("%d",&n)!=EOF){
        b=0;
        while(n){
            if(n%10!=1&&n%10!=2&&n%10!=3&&n%10!=4){
                b+=n%10;
                if(n/10!=0){
                    b*=10;
                }
            }
            n/=10;
        }
        //printf("%d",b);
        if(b%7!=0){
            printf("%d\n",b*10000+a[7-b%7]);
        }
        else{
            printf("%d\n",b*10000+a[0]);
        }
    }
}
