#include <set>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#define LOCAL
using namespace std;
int get(char x){
    if(x>='0'&&x<='9'){
        return x-'0';
    }
    else{
        return x-'a'+10;
    }
}
set <int> ans;
bitset<1007> h[1007],c[1007];
int m,f,n,d,q,a[107];
int main()
{
    #ifdef LOCAL
    freopen("filter.in","r",stdin);
    freopen("filter.out","w",stdout);
    #endif

    string b;
    scanf("%d",&m);
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    int num=0;
    memset(h,0,sizeof(h));
    for(int i=0;i<n;i++){
        cin>>b;
        for(int j=0;j<b.size();j++){
            int now=get(b[j]);
            for(int k=0;k<4;k++){
                if((1<<k)&now){
                    h[i][j*4+k]=1;
                }
            }
        }
        //for(int j=0;j<m;j++){
            //cout<<h[i][j];
        //}
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&d);
        for(int j=0;j<f;j++){
            c[i][(d%m)*(a[j]%m)%m]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            if((h[i]&c[j])==c[j]){
                ans.insert(i);
            }
        }
    }
    printf("%d",ans.size());
    for (std::set<int>::iterator it=ans.begin(); it!=ans.end(); ++it)
        cout << ' ' << *it;
    printf("\n");
    return 0;
}
