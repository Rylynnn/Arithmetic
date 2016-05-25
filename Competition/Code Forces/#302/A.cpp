/*统计有多少个不同的字母*/
#include <bits/stdc++.h>
using namespace std;
map <char,int>h;
int main()
{
    string q;
    int k,p,num,now,len,ans[107];
    scanf("%d",&k);
    cin>>q;
    p=0,num=0,now=0;
    len=q.size();
    memset(ans,0,sizeof(ans));
    for(int i=0; i<len; i++) {
        if(!h[q[i]]) {
            ans[num]=i;
            num++;
            h[q[i]]=1;
        }
    }
    //cout<<num;
    if(num<k) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
        int i;
        for(i=0; i<k-1; i++) {
            for(int j=ans[i]; j<ans[i+1]; j++) {
                printf("%c",q[j]);
                //cout<<j<<endl;
            }
            printf("\n");
        }
        for(i=ans[k-1]; i<len; i++) {
            printf("%c",q[i]);
        }
        printf("\n");
    }
    return 0;
}
