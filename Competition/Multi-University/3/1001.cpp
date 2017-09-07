#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

int len;
char s[105];
const char times[9][11]={"1","3","15","255","65535","4294967295"};
const char l[9]={1,1,2,3,5,10};

bool bigger(int i) {
    if(len!=l[i]) {
        return len>l[i];
    }
    return strcmp(s,times[i])>0;
}

int main() {
    while(1==scanf("%s",s)) {
        len=strlen(s);
        if(len==1&&s[0]=='0') {
            printf("TAT\n");
            continue;
        }
        int i=0;
        while(bigger(i)&&i<6) {
            ++i;
        }
        if(i<6) {
            printf("%d\n",i);
        }
        else {
            printf("TAT\n");
        }
    }
    return 0;
}
