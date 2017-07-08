/*
ID:15829681
LANG:C++
TASK:preface
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct node{
    int num[7];
};
string rom[7] = {"I", "V", "X", "L", "C", "D", "M"};
string a[4][10] = {" ", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                   " ", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "LC",
                   " ", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                   " ", "M", "MM", "MMM"};
string b;
node ans[3509];
void init(){
    for(int i=0;i<=3500;i++){
        memset(ans[i].num,0,sizeof(ans[i].num));
    }
    for (int i=0;i<=3500;i++){
        ans[i] = ans[i-1];
        int now = i;
        int p;
        int ttmp = 0;
        while(now){
            p = now % 10;
            b = a[ttmp][p];
            for (int j=0;j<b.size();j++){
                if(b[j] == 'I'){ans[i].num[0]++;}
                else if(b[j] == 'V'){ans[i].num[1]++;}
                else if(b[j] == 'X'){ans[i].num[2]++;}
                else if(b[j] == 'L'){ans[i].num[3]++;}
                else if(b[j] == 'C'){ans[i].num[4]++;}
                else if(b[j] == 'D'){ans[i].num[5]++;}
                else if(b[j] == 'M'){ans[i].num[6]++;}
            }
            now = now / 10;
            ttmp++;
        }
    }
}
int main()
{
    init();
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i=0;i<7;i++){
        if(ans[n].num[i] != 0){
            cout << rom[i] << ' ' << ans[n].num[i] << endl;
        }
    }
    return 0;
}
