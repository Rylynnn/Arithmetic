#include <cstdio>
#define N 5600
int lm[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int nm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leap(int n){
    if(n%400==0){
        return true;
    }
    else if(n%4==0&&n%100!=0){
        return true;
    }
    return false;
}
int main()
{
    int t,y,m,d,n;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d%d%d",&y,&m,&d,&n);
            int num=0;
            int p=0;
            int now=d;
            int day=1;
            for(int i=0;i<=N;i++){
                if(i==N){
                    if(leap(y+i)){
                    for(int j=1;j<m;j++){
                        if(p==0){
                            p=1;
                            j=m;
                        }
                        while(now<=lm[j]){
                            if(now==1||now==11||now==21){
                                num++;
                            }//printf("%d %d %d %d\n",y+i,day%7,j,now);
                            day+=7;
                            now+=7;
                        }//printf("%d %d %d %d\n",y+i,lm[j],j,now);
                        now=now-lm[j];
                        }
                    }
                    else if(!leap(y+i)){
                        for(int j=1;j<m;j++){
                            if(p==0){
                                p=1;
                                j=m;
                            }
                            while(now<=nm[j]){
                                if(now==1||now==11||now==21){
                                    //printf("%d %d %d\n",y+i,j,now);
                                    num++;
                                }
                                day+=7;
                                now+=7;
                            }
                            now=now-nm[j];
                        }
                    }
                }
                if(leap(y+i)){
                    for(int j=1;j<=12;j++){
                        if(p==0){
                            p=1;
                            j=m;
                        }
                        while(now<=lm[j]){
                            if(now==1||now==11||now==21){
                                num++;
                            }//printf("%d %d %d %d\n",y+i,day%7,j,now);
                            day+=7;
                            now+=7;
                        }//printf("%d %d %d %d\n",y+i,lm[j],j,now);

                        now=now-lm[j];

                    }
                }
                else if(!leap(y+i)){
                    for(int j=1;j<=12;j++){
                        if(p==0){
                            p=1;
                            j=m;
                        }
                        while(now<=nm[j]){
                            if(now==1||now==11||now==21){
                                //printf("%d %d %d\n",y+i,j,now);
                                num++;
                            }
                            day+=7;
                            now+=7;
                        }
                        now=now-nm[j];
                    }
                }
            }
            printf("%d\n",num);
        }
    }
}
