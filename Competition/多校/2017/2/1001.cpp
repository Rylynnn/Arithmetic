/*************************************************************************
    > File Name: 1001.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月27日 星期四 12时13分17秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n, x, y, x1, y1;
    string a, b;
    scanf("%d", &t);
    while(t--){
        cin >> n >> x1 >> y1;
        cin >> a >> b;
        int num = 0;
        x = min(x1, y1);
        y = max(x1, y1);
        if(y > n){
            cout << "Lying" << endl;
            break;
        }
        for(int i=0;i<n;i++){
            if(a[i] == b[i]){
                num++;
            }
        }
        int same, nsame;
        //cout << same << ' ' << nsame << endl;
        if(n - num <= y && 2 * num >= (x + y)){
            cout << "Not lying" << endl;
        }
        else{
            cout << "Lying" << endl;
        }
    }
    return 0;
}
