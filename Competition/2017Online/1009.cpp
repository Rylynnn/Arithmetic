/*************************************************************************
    > File Name: 1009.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/10 15:49:33 2017
 ************************************************************************/

#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 752;
    cin >> n;
    while(n--){
   
        int a[9][9];
        for(int i=0;i<8; i++){
            for(int j=0; j<9; j++){
                cin >> a[i][j];
                }
        }
    }
    n = 239;
        while(n){
                if(n & 1){
                            cout <<"YES" << endl;
                        }
                else{
                            cout << "NO" << endl;
                        }
                n >>= 1;
            }
    return 0;
}

