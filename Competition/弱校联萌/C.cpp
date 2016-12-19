/*
wa1:t的时间标错
wa2:it的实现可能都不太一样。。。= =
*/
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define N 1000005
using namespace std;
struct node{
    string s;
    int a;
    int t;
    bool operator < (const node& x)const{
        if(x.a!=a){
            return a>x.a;
        }
        return t>x.t;
    }
    bool operator == (const node& x)const{
        return (x.a==a&&x.s==s&&x.t==t);
    }
}acm,now;
set<node>x;
map<string,node>h;
set<node>::iterator it,iit;
int main()
{
    //freopen("rylynnn.txt","w",stdout);
	int n,m,lw,li,nlw,nli;
	int tmp;
	string ss;
	while(scanf("%d",&n)!=EOF){
        x.clear();
        h.clear();
        for(int i=1;i<=n;i++){
            cin>>acm.s;
            scanf("%d",&acm.a);
            acm.t=i;
            x.insert(acm);
            h[acm.s]=acm;
        }
        tmp=n/5;
        lw=tmp;
        li=n-tmp;
        int num=1;
        for(it=x.begin();it!=x.end();it++,num++){
            if(num==lw+1){
                break;
            }
        }
        scanf("%d",&m);
        string obey;
        num=n;
        for(int i=1;i<=m;i++){
            cin>>obey;
            if(obey=="+"){
                n++;
                tmp=n/5;
                nlw=tmp;
                nli=n-tmp;
                cin>>now.s>>now.a;
                now.t=i+num;
                if(nlw!=lw){//如果加入后两个区间的长度改变
                    if(now<(*it)){//查看现在应加入哪个区间
                        printf("%s is working hard now.\n",now.s.c_str());
                        x.insert(now);
                        h[now.s]=now;
                    }
                    else{
                        printf("%s is not working now.\n",now.s.c_str());
                        printf("%s is working hard now.\n",(*it).s.c_str());
                        x.insert(now);
                        h[now.s]=now;
                        it++;
                    }
                    lw=nlw;
                    li=nli;
                }
                else{
                    if(it==x.begin()){
                        printf("%s is not working now.\n",now.s.c_str());
                        x.insert(now);
                        h[now.s]=now;
                        it=x.begin();
                    }
                    else{
                        it--;
                        //cout<<(*iit).s;
                        if(now<(*it)){
                            printf("%s is working hard now.\n",now.s.c_str());
                            printf("%s is not working now.\n",(*it).s.c_str());
                            x.insert(now);
                            h[now.s]=now;
                        }
                        else{
                            printf("%s is not working now.\n",now.s.c_str());
                            x.insert(now);
                            h[now.s]=now;
                            it++;
                        }
                    }
                    lw=nlw;
                    li=n-lw;
                }
            }
            else{
                cin>>ss;
                n--;
                tmp=n/5;
                nlw=tmp;
                nli=n-tmp;
                if(nlw!=lw){
                    if(h[ss]<*it){//如果要删的值在w区间内，且因此w区间长度减少
                        x.erase(h[ss]);
                    }
                    else{
                        it--;
                        printf("%s is not working now.\n",(*it).s.c_str());
                        x.erase((h[ss]));
                    }
                    lw=nlw;
                    li=nli;
                }
                else{
                    if(h[ss]<*it){//如果要删的值在w区间内，且因此w区间并未减少
                        printf("%s is working hard now.\n",(*(it)).s.c_str());
                        it++;
                        x.erase(h[ss]);
                    }
                    else{
                        if(h[ss]==(*it)){
                            it++;
                        }
                        x.erase(h[ss]);
                    }
                    lw=nlw;
                    li=nli;
                }
            }
        }
	}
	return 0;
}
