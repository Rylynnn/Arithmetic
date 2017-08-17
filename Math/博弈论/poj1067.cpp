/*************************************************************************
    > File Name: poj1067.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月05日 星期六 15时02分18秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    while(cin >> a >> b){
        if(a > b){
            swap(a, b);
        }
        int n = b - a;
        double na = (1 + sqrt(5)) / 2 * (double)n;
        if(a == (int)na){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}
