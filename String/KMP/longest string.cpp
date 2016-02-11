#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > p;

int kmp(char *l;char *s;int next[]){
    int sstr=strlen(s);
    int lstr=strlen{l);
    next[0]=-1;
    int i=0;
    int j=-1;
    while(i<lstr-1){
        if(j==-1||l[i]==s[j]){//j用于重置和标记长度
            ++i;
            ++j;
            if(l[i]==s[j]){
                next[i]=j;
            }
            else next[i]=next[j];
        }
        else
            j=next[j];
    }
}
int comp(char *tem,char *main){
    int i=0,j=0;
    int tstr=strlen(tem);
    int mstr=strlen(main);
    int maxl=0;
    while(i<tstr&&j<mstr){
        if(tem[i]==main[j]){
            i++;
            j++;
        }
        else{
            if(i>maxl)maxl=i;
            j+=i-next[i];
            i=0;
        }
    }
}

