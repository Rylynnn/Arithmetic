#include <cstdio>
int main()
{
    int x1,x2,y1,y2,x,y,n,xx,yy;
    while(scanf("%d%d",&x,&y)!=EOF){
        scanf("%d",&n);xx=0;yy=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            if((x2==x1+y1&&y2==x1+y1)||(x2!=x1+y1&&y2!=x1+y1)){
                continue;
            }
            if(x2==x1+y1){
                xx++;
            }
            if(y2==x1+y1){
                yy++;
            }
            if(xx>x||yy>y){
                if(xx>x){
                    printf("A\n");
                    printf("%d\n",yy);
                    break;
                }
                else if(yy>y){
                    printf("B\n");
                    printf("%d\n",xx);
                    break;
                }
            }
        }
    }
    return 0;
}
