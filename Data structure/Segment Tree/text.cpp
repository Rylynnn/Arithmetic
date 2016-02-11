#include<stdio.h>
int a[10000];
struct haha
{
    int left;
    int right;
    int num;
}node[10000*4];
void build(int left,int right,int i)
{
    node[i].left=left;
    node[i].right=right;
    node[i].num=0;

            printf("%d:%d %d:%d\n",i,node[i].left,node[i].right,node[i].num);
    if(left==right)
    {
        return ;
    }
    int mid=(left+right)/2;
    build(left,mid,i*2);
    build(mid+1,right,i*2+1);
}
int query(int left,int right,int nd)
{
    int mid=(node[nd].left+node[nd].right)/2;
    if(node[nd].left==left&&node[nd].right==right)
    {
        return node[nd].num;
    }

    if(right<=mid)
    {
          return query(left,right,nd*2);
    }
    else if(left>mid)
    {
        return query(left,right,nd*2+1);
    }
    else
    {
        return query(left,mid,nd*2)+query(mid+1,right,nd*2+1);
    }
}
void update(int pos,int nd)
{

    if(node[nd].left==node[nd].right) {node[nd].num++;return ;}

    int mid=(node[nd].left+node[nd].right)/2;
    if(pos<=mid)  update(pos,nd*2);
    else update(pos,nd*2+1);
    node[nd].num=node[nd*2].num+node[nd*2+1].num;
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
          for(i=0;i<n;i++)
              scanf("%d",&a[i]);
          build(0,n-1,1);
          int sum=0;
          for(i=0;i<n;i++)
          {
              //printf("i=%d  sum=%d\n",i,sum);
              sum+=query(a[i],n-1,1);
              //printf(">>>");
              update(a[i],1);
          }
          for(i=1;i<2*n;i++){
            printf("%d:%d %d:%d\n",i,node[i].left,node[i].right,node[i].num);
		}
         // printf("%d\n",sum);
          int ans=99999999;
          if(ans>sum)  ans=sum;
           for(i=0;i<n;i++)
           {
               sum=sum-a[i]+n-1-a[i];
               if(ans>sum) ans=sum;
           }

               printf("%d\n",ans);
    }
    return 0;
}
