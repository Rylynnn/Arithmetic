#include <bits/stdc++.h>
#define N 10007
using namespace std;
long long f[21]={0,1,2,5,14,46,166,652,2780,12644,61136,312676,1680592,9467680,55704104,341185496,2170853456,14314313872,97620050080,687418278544,4989946902176};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        else{
            printf("%I64d\n",f[n]);
        }
    }
    return 0;
}
