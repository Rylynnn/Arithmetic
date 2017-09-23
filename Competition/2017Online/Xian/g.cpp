/*************************************************************************
    > File Name: g.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 六  9/16 14:30:46 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct node{
    vector<int> son;
    int fa;
}tree[50007]; 
int n, q;

int main()
{
    ios::sync_with_stdio(false);
    cie.tie(0);
    cin >> n >> q;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        if(u > v) swap(u, v);
        tree[u].son.push_back(v);
    }
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<q; ++i){
        cin
    
