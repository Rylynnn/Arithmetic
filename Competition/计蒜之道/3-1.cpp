#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
int pow_mod(LL a,LL b)
{
    LL ret=1;
    while(b)
	{
        if(b&1) ret=multi(ret,a)%p;
        a=multi(a,a)%p;
        b>>=1;
    }
    return ret;
}

int main()
{
    string a;
    int be,bb,p1,p2,p3,en,num;
    while(cin>>a){
        if(a[0]=='+'){
            p1=0;
            be=0;
            p2=0,p3=0;
            en=0;
            num=1;
            bb=1;
            for(int i=1;i<a.size();i++){
                if(a[i]!='e'&p2==0){
                    if(a[i]!='.'){
                        if(p1==0){
                            be=be*10+a[i]-'0';
                        }
                        else{
                            bb=bb*10+a[i]-'0';
                            num++;
                        }
                    }
                    else{
                        p1=1;
                        continue;
                    }
                }
                else if(a[i]=='e'){
                    p2=1;
                    continue;
                }
                else if(p2==1){
                    if(a[i]=='+'){
                        continue;
                    }
                    else if(a[i]=='-'){
                        p3=1;
                        continue;
                    }
                    else{
                        en=en*10+a[i]-'0';
                    }
                }
            }
            int p;
            p=pow(10,num);
            if(bb%p==0){
                printf("%de",be);
            }
            else{
                printf("%d.",be);
                bb%=p;
                for(int j=num-1;j>=0;j--){
                    p=pow(10,j);
                    bb%=p;
                    printf("%d",bb/p);
                }
                cout<<'e';
            }
            if(p3==1){
                printf("-%d",en);
            }
            else{
                printf("%d",en);
            }
        }
        else if(a[0]=='-'){
            p1=0;
            be=0;
            p2=0,p3=0;
            en=0;
            num=1;
            bb=1;
            for(int i=1;i<a.size();i++){
                if(a[i]!='e'&&p2==0){
                    if(a[i]!='.'){
                        if(p1==0){
                            be=be*10+a[i]-'0';
                        }
                        else{
                            bb=bb*10+a[i]-'0';
                            num++;
                        }
                    }
                    else{
                        p1=1;
                        continue;
                    }
                }
                else if(a[i]=='e'){
                    p2=1;
                    continue;
                }
                else if(p2==1){
                    if(a[i]=='+'){
                        continue;
                    }
                    else if(a[i]=='-'){
                        p3=1;
                        continue;
                    }
                    else{
                        en=en*10+a[i]-'0';
                    }
                }
            }
            int p;
            p=pow(10,num);
            if(bb%p==0){
                printf("%de",be);
            }
            else{
                printf("%d.",be);
                bb%=p;
                for(int j=num-1;j>=0;j--){
                    p=pow(10,j);
                    bb%=p;
                    printf("%d",bb/p);
                }
                cout<<'e';
            }
            if(p3==1){
                printf("-%d\n",en);
            }
            else{
                printf("%d\n",en);
            }
        }
        else{
            p1=0;
            be=0;
            p2=0,p3=0;
            en=0;
            num=1;bb=1;
            for(int i=0;i<a.size();i++){
                if(a[i]!='e'&&p2==0){
                    if(a[i]!='.'){
                        if(p1==0){
                            be=be*10+a[i]-'0';
                            //cout<<be<<endl;
                        }
                        else{
                            bb=bb*10+a[i]-'0';
                            num++;
                        }
                    }
                    else{
                        p1=1;
                        continue;
                    }
                }
                else if(a[i]=='e'){
                    p2=1;
                    continue;
                }
                else if(p2==1){
                    if(a[i]=='+'){
                        continue;
                    }
                    else if(a[i]=='-'){
                        p3=1;
                        continue;
                    }
                    else{
                        en=en*10+a[i]-'0';
                    }
                }
            }
            int p;
            p=pow(10,num);
            cout<<p;
            if(bb%p==0){
                printf("%de",be);
            }
            else{
                printf("%d.",be);
                bb%=p;
                for(int j=num-1;j>=0;j--){
                    p=pow(10,j);
                    bb%=p;
                    printf("%d",bb/p);
                }
                cout<<'e';
            }
            if(p3==1){
                printf("-%d",en);
            }
            else{
                printf("%d",en);
            }
        }
    }
    return 0;
}
