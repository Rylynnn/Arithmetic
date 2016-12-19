#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int mx=550;
int L[mx],W[mx],H[mx],l[mx],w[mx],p[mx];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>L[i]>>W[i]>>H[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>l[i]>>w[i]>>p[i];
	int ans=0;
	for(int i=0;i<n;i++){
		int ret=INF;
		for(int j=0;j<m;j++){
			int cur=l[j]/H[i];
			if(cur){
				cur*=w[j];
				cur=(2*(L[i]+W[i])+cur-1)/cur;
				cur*=p[j];
				ret=min(ret,cur);
			}
		}
		ans+=ret;
	}
	cout<<ans<<endl;
	return 0;
}
