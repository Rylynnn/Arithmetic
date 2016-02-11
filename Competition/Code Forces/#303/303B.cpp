#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
int main()
{
    string a,b;
    char sr[N],sl[N],s[N];
    char n[2]={0,1};
    int i,j,num;
    while(cin>>a>>b){
        int p=0;
        for(i=0;i<a.size();i++){
            if(a[i]==b[a.size()-1-i]){
                num=i;
                p=1;
                //printf("%d",num);
                break;
            }
        }
    if(p==1){
        for(i=0;i<=num-1;i++){
            sr[i]=a[i];
            //printf("%c ",sr[i]);
        }
        if(a[num]=='0'){
            sr[num]='1';
        }
        else{
            sr[num]='0';
        }
        //for(i=0;i<=num;i++){
            //printf("%c",sr[i]);
        //}
        int k=0;
        for(i=a.size()-num;i<a.size();i++){
            sl[k++]=b[i];
        }
        if(b[num]=='0'){
            sl[num]='1';
        }
        else{
            sl[num]='0';
        }
        //for(i=0;i<=num;i++){
            //printf("%c",sl[i]);
        //}
        for(i=0;i<num;i++){
            if(sr[i]!=sl[num-1-i]){
                printf("%c",sr[i]);
            }
            else break;
        }
        for(i=0;i<num;i++){
            printf("%c",sl[i]);
        }
    }
    else printf("impossible");
    }
}
