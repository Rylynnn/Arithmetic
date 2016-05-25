/*
ID: 15829681
LANG: C++
TASK: beads
*/
/*
ÇÐ¸îµã×óÓÒmax(br[i],rr[i])+max(bl[i+1],rl[i+1])
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define N 800
#define CLE(a) memset(a,0,sizeof(0))
using namespace std;
int n,br[N],bl[N],rr[N],rl[N];
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    string a,s;
    int ans;
    while(scanf("%d",&n)!=EOF){
        cin>>a;
        CLE(br);
        CLE(bl);
        CLE(rr);
        CLE(rl);
        ans=-1;
        s=a+a;
        s=" "+s;
        br[0]=rr[0]=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='r'){
                rr[i]=rr[i-1]+1;
                br[i]=0;
            }
            else if(s[i]=='b'){
                br[i]=br[i-1]+1;
                rr[i]=0;
            }
            else if(s[i]=='w'){
                br[i]=br[i-1]+1;
                rr[i]=rr[i-1]+1;
            }
            if(br[i]>n){
                br[i]=n;
            }
            if(rr[i]>n){
                rr[i]=n;
            }
        }
        bl[s.size()]=rl[s.size()]=0;
        for(int i=s.size()-1;i>0;i--){
            if(s[i]=='r'){
                rl[i]=rl[i+1]+1;
                bl[i]=0;
            }
            else if(s[i]=='b'){
                bl[i]=bl[i+1]+1;
                rl[i]=0;
            }
            else if(s[i]=='w'){
                bl[i]=bl[i+1]+1;
                rl[i]=rl[i+1]+1;
            }
            if(bl[i]>n){
                bl[i]=n;
            }
            if(rl[i]>n){
                rl[i]=n;
            }
        }
        // num=0;
        for(int i=1;i<s.size();i++){
            ans=max(ans,max(br[i],rr[i])+max(bl[i+1],rl[i+1]));
            //num=i;
        }
        //cout<<num;
        printf("%d\n",min(ans,n));
    }

    return 0;
}
