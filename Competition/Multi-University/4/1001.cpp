#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char t[100050],p[100050];
int f[100050];
int ans[100050],num = 0;

void getfail(char* p,int* f)
{
    int m=strlen(p);
    f[0]=f[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=f[i];
        while(j&&p[j]!=p[i]) j=f[j];
        f[i+1]=(p[i]==p[j])?j+1:0;
    }
}

void kmp(char* t,char* p,int* f)
{
    int n=strlen(t),m=strlen(p);
    getfail(p,f);
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j&&p[j]!=t[i]) j=f[j];
        if(p[j]==t[i]) j++;
        if(j==m)
        {
            ans[num++] = i - m + 1;
            j=f[j];
        }
    }
}

int main(){
    scanf("%s",t);
    scanf("%s",p);
    kmp(t,p,f);
    for(int i = 0; i < num; i ++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
