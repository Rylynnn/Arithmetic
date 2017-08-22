/*************************************************************************
    > File Name: xdoj1187.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月17日 星期四 04时44分24秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100007
using namespace std;
struct edge{
    vector<int> g;
    int num;
}e[N];
pair<int, int> h[N];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int tmp = sqrt(m) + 1;
        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            h[cnt++] = make_pair(a, b);
            e[b].g.push_back(a);
            e[b].num++;
            e[a].g.push_back(b);
            e[a].num++;
        }
        for(int i=0; i<m; i++){
            :

