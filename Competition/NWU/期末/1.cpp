#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
char a[10007];
char b[10007][10007];
int main()
{
    int i=0,len;
    while(gets(a)) {
        len=strlen(a);
        i=0;
        //printf("%s %d",a,len);
        int k=0,j=0;
        while(i<len) {

            if(a[i]==' ') {
                k++;
                j=0;
                i++;
                //continue;
            }
            b[k][j++]=a[i];
            //cout<<b[k][j-1]<<i;
            i++;
        }
        for(i=k; i>0; i--) {
            printf("%s ",b[i]);
        }
        printf("%s",b[0]);
    }
    return 0;
}
