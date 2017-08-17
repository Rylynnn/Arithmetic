/*************************************************************************
    > File Name: hdu4642.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月05日 星期六 15时38分52秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int board[107][107];
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d", &board[i][j]);
            }
        }
        if(board[n][m] == 1){
            printf("Alice\n");
        }
        else{
            printf("Bob\n");
        }
    }
    return 0;
}
