/*
ID:15829681
LANG:C++
TASK:namenum
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#define N 5005
#define LOCAL
using namespace std;
long long b[N];
int main()
{
    FILE *f=fopen("dict.txt","r");
    #ifdef LOCAL
        freopen("namenum.in","r",stdin);
        freopen("namenum.out","w",stdout);
    #endif // LOCAL
    map<char,int>a;
    int k=2,i,j;
    long long c;
    char dic[N][20];
    for(i=0;i<24;){
        if('A'+i=='Q'){
            i++;
        }
        a['A'+i]=k;
        i++;
        if('A'+i=='Q'){
            i++;
        }
        a['A'+i]=k;
        i++;
        if('A'+i=='Q'){
            i++;
        }
        a['A'+i]=k;
        i++;
        k++;
    }
    a['Q']=0;
    a['Z']=0;
    i=0;
    memset(b,0,sizeof(b));
    while(fscanf(f,"%s",dic[i])!=EOF){
        for(j=0;j<strlen(dic[i]);j++){
            b[i]=b[i]*10+a[dic[i][j]];
            //printf(
        }
        //printf("%d ",b[i]);
        i++;
    }
    scanf("%lld",&c);
    int p=0;
    for(j=0;j<=i;j++){
        if(b[j]==c){
            cout<<dic[j]<<endl;
            p=1;
        }
    }
    if(!p){
        printf("NONE\n");
    }
}
