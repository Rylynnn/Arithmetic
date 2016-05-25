#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map <string,int>h;
int main()
{
    cin.sync_with_stdio(false);
    int n;
    string a;
    cin>>n;
    h.erase(h.begin(),h.end());
    while(n--){
        cin>>a;
        sort(a.begin(),a.end());
        cout<<h[a]<<endl;
        h[a]++;
    }
    return 0;
}
