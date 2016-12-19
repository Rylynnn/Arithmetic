#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int i,j,k,l,n,x,t,Q,num;
set <pair<pair<int,int>,string> > T;
set <pair<pair<int,int>,string> > ::iterator it,itt;
map <string,pair<int,int> > S;
string s,p;
pair <int,int> temp;
pair<pair<int,int>,string> te;
void printh(string s)
{
    cout<< s << " is working hard now." << '\n';
}
void printn(string s)
{
    cout<< s << " is not working now." << '\n';
}
int main()
{
    freopen("test2.out","w",stdout);
    cin >> n;
    for (i=1; i<=n; i++)
    {
        cin >> s >> x;
        T.insert(mp(mp(-x,-i),s));
        S[s]=mp(-x,-i);
    }
    for (i=2,it=T.begin(); it!=T.end() && i<=(int)(n*0.2); i++) it++;
    cin >> Q;
    num=n;
    for (i=1; i<=Q; i++)
    {
        cin >> p;
//        cout << (*it).se << "  asd\n";
        if (p=="+")
        {
            cin >> s >> x;
            x*=-1;
            if (num<5)
            {
                num++;
                if (num==5)
                {
                    if ((*T.begin()).fi.fi>=x) printh(s);
                    else
                    {
                        printn(s);
                        printh((*T.begin()).se);
                    }
                }
                else
                {
                    printn(s);
                }
                T.insert(mp(mp(x,-(i+n)),s));
                S[s]=mp(x,-(i+n));
                it=T.begin();
                continue;
            }
            if ((num+1)%5==0)
            {
                itt=it;
                itt++;
                t=(*itt).fi.fi;
                if ((*itt).fi.fi>=x)
                {
                    printh(s);
                    if ((*it).fi.fi>=x) te=*it;
                    else te=mp(mp(x,-(i+n)),s);
                }
                else
                {
                    printn(s);
                    printh((*itt).se);
                    te=*itt;
                }
                T.insert(mp(mp(x,-(i+n)),s));
                S[s]=mp(x,-(i+n));
                it=T.find(te);
                num++;
            }
            else
            {
                itt=it;
                if ((*itt).fi.fi>=x)
                {
                    printh(s);
                    printn((*itt).se);
                    te=*it;
                }
                else
                {
                    printn(s);
                    it++;
                    if ((*it).fi.fi>=x) te=mp(mp(x,-(i+n)),s);
                    else te=*it;
                }
                T.insert(mp(mp(x,-(i+n)),s));
                S[s]=mp(x,-(i+n));
                it=T.find(te);
                it--;
                num++;
            }
        }
        else
        {
            cin >> s;
            temp=S[s];
//            cout << temp.fi <<' ' << temp.se << '\n';
            S.erase(s);
            itt=T.find(mp(temp,s));
            if (num<=5)
            {
                if (num==5) printn((*it).se);
                T.erase(itt);
                num--;
                continue;
            }
            if (num%5==0)
            {
                if (it==itt) it--;
                else
                {
                    if (((*it).fi.fi<(*itt).fi.fi) ||
                        (((*it).fi.fi==(*itt).fi.fi)&&((*it).fi.se<(*itt).fi.se)))
                    {
                        printn((*it).se);
                        it--;
                    }
                }
                te=*it;
            }
            else
            {
                if (temp.fi<(*it).fi.fi || (temp.fi==(*it).fi.fi && temp.se<=(*it).fi.se))
                {
//                    cout << (*it).se << '\n';
                    it++;
                    printh((*it).se);
                }
                te=*it;
            }
            T.erase(itt);
            it=T.find(te);
            num--;
        }
//        cout << (*it).se << "  qwe\n";
    }
    return 0;
}
/*
11
a 1
b 2
c 3
d 4
e 5
q 6
o 8
i 9
ee 12
r 33
er 2
10
+ bb 12
bb is working hard now.


5
Laplant 5
Varnes 2
Warchal 7
Rascon 5
Burdon 0
12
- Burdon
- Rascon
+ A 1
+ B 2
+ C 3
+ D 4
+ E 5
+ F 6
+ G 100
- Warchal
+ SB 1000
- G

5
Laplant 5
Varnes 2
Warchal 2
Rascon 5
Burdon 0
12
- Burdon
- Rascon
+ A 1
+ B 2
+ C 3
+ D 4
+ E 5
+ F 6
+ G 100
- Warchal
+ SB 1000
- G
*/
