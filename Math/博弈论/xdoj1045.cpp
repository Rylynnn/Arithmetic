/*************************************************************************
    > File Name: xdoj1045.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月05日 星期六 16时23分39秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int t;
int m[5][5], flag;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string a;
bool dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
            if(m[nx][ny] == 0){
                m[nx][ny] = 1;
                if(!dfs(nx, ny)){
                    m[nx][ny] = 0;
                    return true;
                }
                m[nx][ny] = 0;
            }
        }
    }
    return false;
}
    
int main()
{
    scanf("%d", &t);
    while(t--){
        memset(m, 0, sizeof(m));
        for(int i=0; i<5; i++){
            cin >> a;
            for(int j=0; j<5; j++){
                m[i][j] = a[j] - '0';
            }
        }
        flag = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(m[i][j] == 0){
                    m[i][j] = 1;
                    if(!dfs(i, j)){
                        flag = 1;
                        break;
                    }
                    m[i][j] = 0;         
                }           
            }
            if(flag){
                break;
            }
        }
        if(flag){
            printf("win\n");
        }
        else{
            printf("lose\n");
        }
    }
    return 0;
}
        
