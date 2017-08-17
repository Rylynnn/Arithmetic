const int MAXN = 400010;
int ch[MAXN][2],fa[MAXN],xo[MAXN];
bool rt[MAXN];
int rev[MAXN],a[MAXN];
void update(int x)
{
	if (!x) return;
	rev[x]^=1;
}
void push_down(int x)
{
    if (rev[x])
    {
    	swap(ch[x][0],ch[x][1]);
    	update(ch[x][0]);
    	update(ch[x][1]);
    	rev[x]=0;
	}
}
void push_up(int x)
{
	xo[x]=xo[ch[x][0]]^xo[ch[x][1]]^a[x];
}
void rotate(int x)
{
    int y=fa[x],p=ch[y][1]==x;
    ch[y][p]=ch[x][!p];
    fa[ch[y][p]] = y;
    fa[x]=fa[y];
    fa[y]=x;
    ch[x][!p]=y;
    if(rt[y])
        rt[y]=false,rt[x]=true;
    else
        ch[fa[x]][ch[fa[x]][1]==y]=x;
    push_up(y);
    push_up(x);
}
void maintain(int x)
{
    if(!rt[x]) maintain(fa[x]);
    push_down(x);
}
void splay(int x)
{
    maintain(x);
    while(!rt[x])
    {
        int f=fa[x], ff=fa[f];
        if(rt[f])
            rotate(x);
        else if( (ch[ff][1]==f)==(ch[f][1]==x) )
            rotate(f),rotate(x);
        else
            rotate(x),rotate(x);
    }
}
void access(int x)
{
    int y=0,z=x;
    for(;x;x=fa[y=x])
    {
        splay(x);
        rt[ch[x][1]]=true,rt[ch[x][1]=y]=false;
        push_up(x);
    }
    splay(z);
}
int findroot(int x)
{
	access(x);
	splay(x);
	while (ch[x][0]!=0) x=ch[x][0];
	return x;
}
bool judge(int x,int y)
{
	return findroot(x)==findroot(y);
}
void mroot(int x)
{
	access(x);
	rev[x]^=1;
}
void cut(int x,int y)
{
	mroot(x);
	splay(y);
	fa[ch[y][0]]=fa[y];
	fa[y]=0;
	rt[ch[y][0]]=true;
	ch[y][0]=0;
	push_up(y);
}
void link(int x,int y)
{
	mroot(x);
	fa[x]=y;
}
int ask(int x,int y)
{
	mroot(x);
	access(y);
	return xo[ch[y][0]]^a[y];
}
int judgeedge(int x,int y)
{
	mroot(x);
	access(y);
	int p=ch[y][0];
	while (ch[p][1])
	    p=ch[p][1];
	return p==x;
}
