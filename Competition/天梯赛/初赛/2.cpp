#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int h,m;
    string hh,mm;
    while(scanf("%d:%d",&h,&m)!=EOF){
        if(h>=0&&h<12){
            if(h<10){
                 if(m<10){
                    printf("Only 0%d:0%d.  Too early to Dang.\n",h,m);
                 }
                 else{
                    printf("Only 0%d:%d.  Too early to Dang.\n",h,m);
                 }
            }
            else{
                if(m<10){
                    printf("Only %d:0%d.  Too early to Dang.\n",h,m);
                }
                else{
                    printf("Only %d:%d.  Too early to Dang.\n",h,m);
                }
            }
        }
        else if(h==12){
            if(m==0){
                printf("Only 12:00.  Too early to Dang.\n",h,m);
            }
            else{
                printf("Dang\n");
            }
        }
        else{
            if(m==0){
                for(int i=1;i<=h-12;i++){
                    printf("Dang");
                }
                printf("\n");
            }
            else{
                for(int i=1;i<=h-12+1;i++){
                    printf("Dang");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
