/*
ID: 15829681
LANG: C++
TASK: gift1
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int n,m,num,aver;
    int i,j,k;
    string s[20],give,now;
    int a[20],out[20];
    fin>>n;
    //memset(out,0,20);
    for(i=1;i<=n;i++){
        fin>>s[i];
    }
    //memset(a,0,20);
    for(i=1;i<=n;i++){
        a[i]=0;
    }
    /*for(i=1;i<=n;i++){
        printf("%d\n",a[i]);
    }*/
    for(i=1;i<=n;i++){
        //printf("%d",i);
        fin>>give>>m>>num;
        if(m==0||num==0)continue;
        //printf("%d%d\n",m,num);
        aver=m/num;
        for(j=1;j<=n;j++){
            if(give==s[j]){
                a[j]+=m%num;
                a[j]-=m;
            }
        }
        while(num--){
            fin>>now;
            for(k=1;k<=n;k++){
                if(now==s[k]){
                    a[k]+=aver;
                    //printf("%d\n",a[k]);
                    //break;
                }
            }
            //printf("\n");
        }
        //for(j=1;j<=n;j++){
          //  printf("%d ",a[j]);
        //}
    }
    for(i=1;i<=n;i++){
        fout<<s[i]<<" "<<a[i]<<"\n";
    }
    return 0;
}






