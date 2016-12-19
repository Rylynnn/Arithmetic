#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
map<int,int> H;
string fir[1100000];
int num,x,n,fin[1100000];
void judge(string a){
    if(a=="insert") {
        cin>>x;
        H[x]++;
        q.push(x);
        num++;
        fir[num]=a;
        fin[num]=x;
    }
    if(a=="removeMin") {
        if(q.empty()) {
            num++;
            fir[num]="insert";
            fin[num]=1;
            num++;
            fir[num]=a;
        }
        else {
            H[q.top()]--;
            q.pop();
            num++;
            fir[num]=a;
        }
    }
    if(a=="getMin") {
        cin>>x;
        if(H[x]!=0) {
            while(q.top()!=x) {
                H[q.top()]--;
                num++;
                fir[num]="removeMin";
                q.pop();
            }
            num++;
            fir[num]=a;
            fin[num]=x;
        }
        else {
            num++;
            fir[num]="insert";
            fin[num]=x;
            H[x]++;
            //cout<<q.top()<<endl;
            q.push(x);
            //cout<<q.top()<<endl;
            while(q.top()!=x) {
                H[q.top()]--;
                num++;
                fir[num]="removeMin";
                q.pop();
            }
            num++;
            fir[num]=a;
            fin[num]=x;
        }
    }
}
int main()
{
    string a;
    while(scanf("%d",&n)!=EOF) {
        while(!q.empty()){
            q.pop();
        }
        num=0;
        for(int i=1; i<=n; i++) {
            cin>>a;
            judge(a);
        }
        cout<<num<<endl;
        for(int i=1; i<=num; i++) {
            cout<<fir[i];
            if(fir[i]!="removeMin"){
                cout<<" "<<fin[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
