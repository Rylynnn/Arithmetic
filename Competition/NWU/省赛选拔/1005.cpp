#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int t,be;
    char a[100];
    char b[100];
    while(scanf("%d",&t)!=EOF){
        while(t--){
            cin>>a;
            int len=strlen(a);
            memset(b,0,sizeof(b));
            for(int i=0;i<len;i++){
                b[i]=!(a[len-1-i]-'0')+'0';
            }//cout<<b;
            if(a==b){
                cout<<a<<endl;
            }
            else{
                int i,j,p=0;
                for(i=0;i<len;i++){
                    if(a[i]==b[0]){
                        be=i;
                        //cout<<be<<' ';
                        for(j=0;j<len-be;j++){
                            if(b[j]!=a[be+j]){
                                break;
                            }
                        }
                        //cout<<be+j;
                        if(be+j-1==len-1){
                            p=1;
                            for(int k=0;k<be;k++){
                                printf("%c",a[k]);
                            }
                            cout<<b<<endl;
                            break;
                        }
                    }
                }
                if(p==0){
                    for(int i=0;i<len;i++){
                        printf("%c",a[i]);
                    }
                    for(int i=0;i<len;i++){
                        printf("%c",b[i]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
