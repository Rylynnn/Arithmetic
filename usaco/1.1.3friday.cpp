/*
ID: 1582968
LANG: C++
TASK: friday
*/
#include<cstdio>
#include<cstring>
bool rn(int n);
int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int a[8];
    int l=13;
    int i,j,n;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        a[l%7]++;l+=31;
        a[l%7]++;
        if(rn(1900+i-1))l+=29;
        else l+=28;
        a[l%7]++;l+=31;
        a[l%7]++;l+=30;
        a[l%7]++;l+=31;
        a[l%7]++;l+=30;
        a[l%7]++;l+=31;
        a[l%7]++;l+=31;
        a[l%7]++;l+=30;
        a[l%7]++;l+=31;
        a[l%7]++;l+=30;
        a[l%7]++;l+=31;
    }
    printf("%d %d %d %d %d %d %d\n",a[6],a[0],a[1],a[2],a[3],a[4],a[5]);
    return 0;
}
bool rn(int n){
    if(n%100==0){
        if(n%400==0){
            return true;
        }
    }
    else if(n%4==0){
        return true;
    }
    return false;
}
