#include<cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string a;
    int i,len,num;
    double n1,n2,n3,ans;
    while(cin>>a){
        num=0;
        len=a.size();
        if(a[0]=='-'){
            n2=1.5;
            i=1;
        }
        else{
            n2=1;
            i=0;
        }
        if((a[len-1]-'0')%2==0){
            n3=2;
        }
        else{
            n3=1;
        }
        for(;i<len;i++){
            if(a[i]-'0'==2){
                num++;
            }
        }
        //cout<<n2<<' '<<n3<<' '<<num<<' '<<len;
        if(n2==1.5){
            ans=((double)num/(double)(len-1))*n2*n3*100;
        }
        else{
            ans=((double)num/(double)len)*n2*n3*100;
        }
        printf("%.2f\%\n",ans);
    }
}
