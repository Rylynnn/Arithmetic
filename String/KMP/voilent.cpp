#include<cstring>
int voilent(char* s,char* p)
{
    int slen=strlen(s);//the length of text string
    int plen=strlen(p);//the length of template string
    int i=0,j=0;
    while(i<slen&&j<plen){
        if(s[i]==p[i]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }//if get the fail match ,backtrack i and reset j
    }
    if(j==plen)return i-j;//return the location of the beginning
    else return -1;
}
