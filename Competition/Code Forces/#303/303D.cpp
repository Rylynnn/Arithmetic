#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j;
    int a[100010];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int sum=0;
    int num=0;
    for(j=0;j<n;j++){
        if(a[j]!=0&&sum<=a[j]){
            num++;
            sum+=a[j];
        }
    }
    printf("%d",num);
}
