#include <bits/stdc++.h>
using namespace std;
int next[37],ll;
char a[37],b[100007];
int main()
{
    int length,i,j,now,num;
    scanf("%s%s",b,a);
    num=now=0;
    while(now<strlen(b)){
        j=now;
        for(i=0;i<strlen(a);){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                break;
            }
        }
        if(i==strlen(a)){
            num++;
            now+=i;
        }
        else{
            now++;
        }
    }
    printf("%d",num);
}
