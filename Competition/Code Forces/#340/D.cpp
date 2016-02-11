#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,x3,y1,y2,y3;
    while(scanf("%d%d%d%d%d%d",&x1,%y1,&x2,&y2,&x3,&y)!=EOF){
        if((x1==x2&&y1==y2)||(x2==x3&&y2==y3)||(x3==x1&&y3==y1)){
            if((x1==x2&&x2==x3)&&(y1==y2&&y2==y3)){
                printf("0\n");
            }
            else if((x1!=x2||x2!=x3||x1!=x3||y1!=y2||y2!=y3||y1!=y3){
                printf()
            }
        }
        if((x1==x2&&x1!=x3)||(x1==x3&&x2!=x1)||(x3==x2&&x1!=x2)||(y1==y2&&y1!=y3)||(y1==y3&&y2!=y1)||(y3==y2&&y1!=y2)){
            printf("2\n");
        }
        else if((x1==x2&&x2==x3)||(y1==y2&&y2==y3)){
            printf("3\n");
        }
        else if((x1!=x2&&x2!=x3&&x1!=x3)||(y1!=y2&&y2!=y3&&y1!=y3)){
            printf("1\n");
        }
    }

}
