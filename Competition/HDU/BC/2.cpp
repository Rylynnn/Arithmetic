#include <iostream>
#include <cstring>

using namespace std;

int f[1005][1005];

int main()
{
    int t,i,j,num,n,p;
    cin >> t;
    while(t--){
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        cin >> n >> p;
        for(i = 1; i <= n; i ++){
            cin >> num;
            num %= p;
            if(num < 0) num +=p;
            for(j = 0; j < p; j ++){
                int temp = j - num;
                if(temp < 0) temp += p;
                f[i][j] = (f[i-1][j] + f[i-1][temp]) % 1000000007;
            }
        }
        cout << f[n][0] << endl;
    }
    return 0;
}
