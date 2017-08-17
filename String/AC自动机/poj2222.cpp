/***********************************************************************
    > File Name: poj2222.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月10日 星期四 15时40分52秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#define N 500010
using namespace std;
struct Trie{//Refer to kuangbin's Template
    int next[N][26], fail[N], end[N];
    int root, num;
    int newnode(){
        for(int i=0; i<26; i++){
            next[num][i] = -1;
        }
        end[num++] = 0;
        return num - 1;
    }
    void init(){
        num = 0;
        root = newnode();
    }
    void insert_p(string buf){
        int len = buf.size();
        int now = root;
        for(int i=0; i<len; i++){
            int tmp = buf[i] - 'a';
            if(next[now][tmp] == -1){
                next[now][tmp] = newnode();
            }
            now = next[now][tmp];
        }
        end[now]++;//the count of leaf node is 1
     //   cout << now;
     //   for(int i=0; i<=num; i++){
     //       cout << i << ' ' << fail[i] << ' ' << end[i] << endl;
     //       for(int j=0; j<=26; j++){
     //           cout << next[i][j] << ' ';
     //       }
     //       cout << endl << endl;
     //   }
    }//
    void build(){
        queue<int> q;
        while(!q.empty()){
            q.pop();
        }
        fail[root] = root;
        for(int i=0; i<26; i++){
            if(next[root][i] == -1){
                next[root][i] = root;
            }
            else{
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i=0; i<26; i++){
                if(next[now][i] == -1){
                    next[now][i] = next[fail[now]][i];
                }
                else{
                    fail[next[now][i]] = next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        } 
     //   for(int i=0; i<=num; i++){
     //       cout << i << ' ' << fail[i] << ' ' << end[i] << endl;
     //       for(int j=0; j<=26; j++){
     //           cout << next[i][j] << ' ';
     //       }
     //       cout << endl;
     //   }
    }//
    int query(string buf){
        int len = buf.size();
        int now = root;
        int ans = 0;
        for(int i=0; i<len; i++){
            int tmp = buf[i] - 'a';
            now = next[now][tmp];
            int temp = now;
            while(temp != root){//每个串只能走一次
                ans += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return ans;
    }
}tree;

int main()
{   
    string buf;
    int t, n;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        tree.init();
        for(int i=0; i<n; i++){
            cin >> buf;
            tree.insert_p(buf);
        }
        tree.build();
//        for(int i=0; i<=tree.num; i++){
//            cout << i << ' ' << tree.fail[i] << ' ' << tree.end[i] << endl;
//            for(int j=0; j<=26; j++){
//                cout << tree.next[i][j] << ' ';
//            }
//            cout << endl;
//        }
        cin >> buf;
        cout << tree.query(buf) << endl;
    }
    return 0;
}
