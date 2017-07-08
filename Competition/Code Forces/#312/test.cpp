#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> > q;
int main()
{
    q.push(1);
    q.push(1000);
    q.push(9);
    while(!q.empty()){
        printf("%d",q.top());
        q.pop();
    }
    return 0;
}
