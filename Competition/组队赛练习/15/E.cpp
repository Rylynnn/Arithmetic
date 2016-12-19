#include <bits/stdc++.h>
#define N 10
using namespace std;
set<int>h;
set<int>::iterator it;
int a[11][11];
int main()
{
    freopen("in.txt","w",stdout);
        for(int j=0;j<=N;j++){
            for(int k=0;k<=N;k++){
                h.clear();
                    for(int q=0;q<=j;q++){
                        for(int m=0;m<=k;m++){
                            h.insert(q*2+m*3);
                        }
                    }
                printf(", %d",h.size());
                }
                printf("\n");
            }
}
