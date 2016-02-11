/*
ID: 15829681
LANG: C++
TASK: ride
*/
#include<stdio.h>
#include<string.h>

char s[10],t[10];
long a=1,b=1;

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    int i;
    scanf("%s%s",s,t);
    for(i=0;s[i];i++)
        a*=s[i]-64;
    for(i=0;t[i];i++)
        b*=t[i]-64;
    if(a%47==b%47)printf("GO\n");
    else printf("STAY\n");
    return 0;
}

