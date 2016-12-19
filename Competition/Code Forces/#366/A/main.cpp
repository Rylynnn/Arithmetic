#include <bits/stdc++.h>
using namespace std;
map<int,int>m;
map<int,int>::iterator it;
vector<int>qq;
int main()
{
    int ans,n,q,num,d,cnt[300007];
    while(scanf("%d%d",&n,&q)!=EOF){
        m.clear();
        memset(cnt,0,sizeof(cnt));
        ans=0;
        int numi=0;
        cnt[0]=0;
        for(int i=1;i<=q;i++){
            scanf("%d%d",&d,&num);
            if(d==1){
                numi++;
                qq.push_back(num);
                m[num]++;
                ans++;
            }
            if(numi!=cnt[i-1]){
                cnt[i]=numi;
            }
            else{
                cnt[i]=cnt[i-1];
            }
            if(d==2){
                ans-=m[num];
                m[num]=0;
            }
            if(d==3){
                 for(int j=0;j<cnt[num];j++){
                    if(m[qq[j]]>0){
                        m[qq[j]]--;
                        ans--;
                    }
                }
            }
            for(int j=0;j<qq.size();j++){
                cout<<qq[j]<<' ';
            }
            cout<<endl;
            for(it=m.begin();it!=m.end();it++){
                cout<<it->first<<' '<<it->second<<' ';
            }
            printf("%d\n",ans);
        }
    }
}
