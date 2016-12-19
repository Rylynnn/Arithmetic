/*
wa1:是从后往前数第k个元音字母- -
wa2：如果不符合任意一种则直接为no
wa3：比的是后缀。。- -
*/
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
map<string,int>h;
int main(){
	int n,k,no;
	string sa[2507][4];
	string a[2507][4];
	while(scanf("%d%d",&n,&k)!=EOF){
        h.clear();
        no=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                sa[i][j].clear();
                cin>>a[i][j];
                int numa=0;
                for(int p=a[i][j].size()-1;p>=0;p--){
                    if(a[i][j][p]=='a'||a[i][j][p]=='e'||a[i][j][p]=='i'||a[i][j][p]=='o'||a[i][j][p]=='u'){
                        numa++;
                        if(numa==k){
                            for(int q=p;q<a[i][j].size();q++){
                                sa[i][j].push_back(a[i][j][q]);
                            }
                            break;
                        }
                    }
                }
                if(numa<k){
                    no=1;
                }
            }
        }
        if(no==1){
            printf("NO\n");
            continue;
        }
        for(int i=0;i<n;i++){
            //cout<<sa[i]<<endl;
            if(sa[i][0]==sa[i][1]&&sa[i][2]==sa[i][3]){
                if(sa[i][0]==sa[i][2]){
                    h["aaaa"]++;
                }
                else{
                    h["aabb"]++;
                }
            }
            else if(sa[i][0]==sa[i][2]&&sa[i][1]==sa[i][3]&&sa[i][0]!=sa[i][1]){
                h["abab"]++;
            }
            else if(sa[i][0]==sa[i][3]&&sa[i][1]==sa[i][2]&&sa[i][0]!=sa[i][1]){
                h["abba"]++;
            }
            else{
                no=1;
            }
        }
        if(no==1){
            printf("NO\n");
            continue;
        }
        if(h["aaaa"]!=0&&h["aabb"]==0&&h["abab"]==0&&h["abba"]==0){
            printf("aaaa\n");
        }
        else if(h["aabb"]!=0&&h["abab"]==0&&h["abba"]==0){
            printf("aabb\n");
        }
        else if(h["aabb"]==0&&h["abab"]!=0&&h["abba"]==0){
            printf("abab\n");
        }
        else if(h["aabb"]==0&&h["abab"]==0&&h["abba"]!=0){
            printf("abba\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
