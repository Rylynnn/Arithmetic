/*************************************************************************
    > File Name: bb.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 22:12:43 2017
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long qq[10];
int a[105];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    memset(a,-1,sizeof(a));
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x]=y;
    }
    if(a[n]!=-1){
        cout<<a[n]<<endl;
		return 0;
    }
    int p1=-1,p2=-1;
    int num=0;
    for(int i=1;i<=100;i++){
        int p=0;
        for(int j=1;j<=100;j++){
            if(p==1) break;
            if(a[j]!=-1){
                if(a[j]!=(j-1)/i+1){
                    p=1;
                    break;
                }
            }
        }
        if(p==0) {
            if(p1==-1){
                p1=(n-1)/i+1;
                num++;
            }
            else {
                p2=(n-1)/i+1;
                if(p2!=p1){
                    num++;
                }
            }
        }

        if(num>1) break;
    }
    if(num == 1){
        cout<<p1<<endl;
    }
    else cout<<-1<<endl;
	return 0;
}

