#include<cstdio>
#include<cstring>
using namespace std;
int next[110];
void kmp(char *tem){//打表表示在第i个字符之前字符串tem前缀相同的真子后缀
    int ts=strlen(tem);
    next[0]=-1;
    int point=-1;
    int t=0;
    while(t<ts){
        if(point==-1||tem[point]==tem[t]){
            ++t;
            ++point;
            if(tem[t]!=tem[point])
                next[t]=point;
            else next[t]=next[point];
        }
        else point=next[point];
    }
}
int findl(char *tem,char *main){//查找模板串在主串中的最大公共子序列长度，返回主串中的位置
    int tstr=strlen(tem);
    int mstr=strlen(main);
    int i=0,j,top=0;//top存储每次匹配时候主串的开始位置
    j=top;
    while(i<tstr&&j<mstr){
        if(tem[i]==main[j]){
            i++;
            j++;
        }
        else{
            top+=i-next[i];
            j=top;
            i=0;
        }
    }
    return top;
}
int main()
{
    char a[110],b[110];
    int loc;
    scanf("%s%s",a,b);
        kmp(b);
        loc=findl(b,a)+1;
        printf("%d\n",loc);
    return 0;
}
