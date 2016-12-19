#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int a[10000000];
int main()
{
    string a;
    int p[10007],len;
    while(getline(cin,a)){
        memset(p,0,sizeof(p));
        len=a.size();
        if(len>1&&a[0]=='\''&&a[len-1]=='\''){
            p[0]=p[len-1]=1;
            for(int i=1;i<len-1;i++){
                if(p[i]!=1){
                    if(a[i]=='\\'){
                        if(p[i+1]!=1&&a[i+1]=='\''){
                            p[i]=p[i+1]=1;
                        }
                        else if(p[i+1]!=1&&a[i+1]=='\\'){
                            p[i]=p[i+1]=1;
                            //cout<<i;
                        }
                        else if(p[i+1]!=1&&a[i+1]=='"'){
                            p[i]=p[i+1]=1;
                        }
                    }
                }
            }
            /*for(int i=0;i<len;i++){
                cout<<p[i]<<' ';
            }*/
            int pp=0;
            for(int i=1;i<len-1;i++){
                if(p[i]==0&&(a[i]=='\''||a[i]=='\\')){
                    pp=1;
                }
            }
            if(pp==0){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else if(len>1&&a[0]=='"'&&a[len-1]=='"'){
            p[0]=p[len-1]=1;
            for(int i=1;i<len-1;i++){
                if(p[i]!=1){
                    if(a[i]=='\\'){
                        if(p[i+1]!=1&&a[i+1]=='"'){
                            p[i]=p[i+1]=1;
                        }
                        else if(p[i+1]!=1&&a[i+1]=='\\'){
                            p[i]=p[i+1]=1;
                        }
                        else if(p[i+1]!=1&&a[i+1]=='\''){
                            p[i]=p[i+1]=1;
                        }
                    }
                }
            }

            int pp=0;
            for(int i=1;i<len-1;i++){
                if(p[i]==0&&(a[i]=='"'||a[i]=='\\')){
                    pp=1;
                }
            }
            if(pp==0){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
