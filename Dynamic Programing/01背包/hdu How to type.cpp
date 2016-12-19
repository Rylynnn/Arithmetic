#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,on[110],off[110],lenth;
    string s;
    cin>>n;
    for(j=1;j<=n;j++){
        cin>>s;
        memset(on,0,sizeof(on));
        memset(off,0,sizeof(off));
        if(s[0]>='a'&&s[0]<='z'){//处理第一个字母的状态
            on[0]=2;//小写则先按字母然后按开
            off[0]=1;//直接按字母
        }
        else{
            on[0]=2;//大写则先按开然后按字母
            off[0]=2;//直接按shift然后按字母
        }
        lenth=s.size();
        for(i=0;i<lenth-1;i++){
            if(s[i+1]>='a'&&s[i+1]<='z'){
                on[i+1]=min(on[i]+1,off[i]+1)+1;//在这种情况下从on状态转移到on状态的最小步数是先按Shift键并按字母键，从off状态转移到on状态的最小步数是先按字母键再按Caps Lock键，所以是off[i-1]+1+1;
                off[i+1]=min(on[i]+1,off[i])+1;
            }
            else{
                on[i+1]=min(on[i],off[i]+1)+1;//从on状态转移到on状态不需要按任何键，直接按字母键即可，从off状态转移到on状态的最少步数是：先按Caps Lock键再按字母键，所以是off[i-1]+1+1;
                off[i+1]=min(on[i]+1,off[i]+1)+1;
            }
        }
        printf("%d\n",min(on[lenth-1]+1,off[lenth-1]));
    }
    return 0;
}
