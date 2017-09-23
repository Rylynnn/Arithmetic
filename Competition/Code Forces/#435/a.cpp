/*************************************************************************
    > File Name: a.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/19 22:58:46 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int n;
    int x;
    int a, b[107], num = 0;
    cin >> n >> x;
    memset(b, 0, sizeof(b));

    for(int i=0; i<n; i++){
        cin >> a;
        b[a] = 1;
    }
    for(int i=0; i<=100; i++){
        if(b[i] == 0 && i < x){
                num++;
        }
    }
    if(b[x] == 1){
        num++;
    }
    cout << num << endl;
    return 0;
}
