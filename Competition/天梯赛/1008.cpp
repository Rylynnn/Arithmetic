#include <iostream>
using namespace std;
int main()
{
    int n,sum;
    int b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char c[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    string a[107];
    cin>>n;
    int p=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=0;
        for(int j=0;j<17;j++){
            if(a[i][j]=='X'){
                sum+=10*b[j];
            }
            else{
                sum+=(a[i][j]-'0')*b[j];
            }
        }
        sum%=11;
        if(c[sum]!=a[i][17]){
            p=1;
            cout<<a[i]<<endl;
        }
    }
    if(p==0){
        cout<<"All passed"<<endl;
    }
    return 0;
}
