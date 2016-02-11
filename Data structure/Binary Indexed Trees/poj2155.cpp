#include<cstdio>
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y){
    while(x<=n){
        while(y<=n){
            bit[x][y]&=1;
            y+=lowbit(y);
        }
        x+=lowbit(y);
    }
}
int getsum
int main(){
}
