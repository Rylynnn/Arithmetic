#include <bits/stdc++.h>
using namespace std;
map <int,int>h;
map <int,int>::iterator it;
typedef struct node{
    int b,m;
    bool operator <(const node& c)const{
        return m<c.m;
    }
}ba;
priority_queue<ba>s;
ba now,n1,n2,n3;
struct name{
    int a[3];
}ball[100007];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int n,k,num;
    while(scanf("%d",&n)!=EOF){
        num=0;
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            h[k]++;
        }
        for(it=h.begin();it!=h.end();it++){
            now.b=it->first;
            now.m=it->second;
            s.push(now);
        }
        while(!s.empty()){
            n1=s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            n1.m--;
            n2=s.top();
            s.pop();
            if(s.empty()){
                break;
            }
            n2.m--;
            n3=s.top();
            s.pop();
            n3.m--;
            ball[num].a[0]=n1.b;
            ball[num].a[1]=n2.b;
            ball[num].a[2]=n3.b;
            num++;
            sort(ball[num-1].a,ball[num-1].a+3,cmp);
            if(n1.m!=0){
                s.push(n1);
            }
            if(n2.m!=0){
                s.push(n2);
            }
            if(n3.m!=0){
                s.push(n3);
            }
        }
        printf("%d\n",num);
        if(num!=0)
        for(int i=0;i<num;i++){
            printf("%d %d %d\n",ball[i].a[0],ball[i].a[1],ball[i].a[2]);
        }
    }
    return 0;
}
