struct data{
   int l,r;
   int min,lazy;
}tr[2000001];
int a[1000050];
int flag=0,pos;
void build(int k,int s,int t)
{
    tr[k].l=s;tr[k].r=t;
    tr[k].lazy=0;
    if(s==t)
	{
		tr[k].min=a[s];		
		return;
	}
    int mid=(s+t)>>1;
    build(k<<1,s,mid);
    build(k<<1|1,mid+1,t);
    tr[k].min=min(tr[k<<1].min,tr[k<<1|1].min);
}
void pushdown(int k)
{
    tr[k<<1].min-=tr[k].lazy;
    tr[k<<1|1].min-=tr[k].lazy;
    tr[k<<1].lazy+=tr[k].lazy;
    tr[k<<1|1].lazy+=tr[k].lazy;
    tr[k].lazy=0;
}
void change(int k,int a,int b,int c)
{
    int l=tr[k].l,r=tr[k].r;
    if(a==l&&b==r)
    {
    	tr[k].min-=c;
    	tr[k].lazy+=c;
    	if (tr[k].min<0)
    	{
    		flag=1;
		}
		return;
	} 
    if(tr[k].lazy) pushdown(k);
    int mid=(l+r)>>1;
    if(b<=mid) change(k<<1,a,b,c);
    else if(a>mid) change(k<<1|1,a,b,c);
    else change(k<<1,a,mid,c),change(k<<1|1,mid+1,b,c);
    tr[k].min=min(tr[k<<1].min,tr[k<<1|1].min);
}
