#include <bits/stdc++.h>
#define MAX 2
using namespace std;
typedef long long int LL;
const int MAXN = 1000000 + 5;
struct Trie{
    int val;
    int child[2];
    Trie(){
        val = 0;
        memset(child, 0, sizeof(child));
    }
}trie[MAXN];
int trieN;
void Insert(string str){
    int d, x = 0;
    for (int i = str.size()-1; i >= 0;i--){
        d = (str[i] - '0') % 2;
        if (trie[x].child[d] == 0){
            trie[x].child[d] = ++trieN;
        }
        x = trie[x].child[d];
    }
    trie[x].val++;
}
int Search(string str){
    int d, x = 0,cnt=0,pos=-1;
    for (int i = 0; str[i]; i++){
        if (str[i] == '1'){
            pos = i; break;
        }
    }
    if (pos != -1){
        for (int i = str.size() - 1; i >= 0; i--){
            d = (str[i] - '0') % 2;
            if (trie[x].child[d] == 0){ return 0; }
            x = trie[x].child[d];
            if (i == pos){ break; } //之后的string都是0
        }
    }
    cnt += trie[x].val;
    while ((x = trie[x].child[0])!=0){ //沿着当前的子树根一直往'0'子树走
        cnt += trie[x].val;
    }
    return cnt;
}
void Delete(string str){
    int x = 0, d;
    for (int i = str.size() - 1; i >= 0; i--){
        d = (str[i] - '0') % 2;
        if (trie[x].child[d] == 0){
            return;
        }
        x = trie[x].child[d];
    }
    trie[x].val == 0 ? trie[x].val = 0 : trie[x].val--;
}
int main()
{
    int t;
    string ob,str;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            cin>>ob>>str;
            if(ob[0]=='+'){
                Insert(str);
            }
            if(ob[0]=='-'){
                Delete(str);
            }
            if(ob[0]=='?'){
                printf("%d\n",Search(str));
            }
        }
    }
}
