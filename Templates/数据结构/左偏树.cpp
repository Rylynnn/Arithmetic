struct lf
{
	int dist;
	LL key;
	int left,right,ll,rr,way;
}nd[maxn];
int merge(int a,int b)
{
	int c;
	if ((a==0)||((b!=0)&&(nd[a].key<nd[b].key))) swap(a,b);
	if (b==0) return a;
	nd[a].right=merge(nd[a].right,b);
	if (nd[nd[a].left].dist<nd[nd[a].right].dist) swap(nd[a].left,nd[a].right);
	nd[a].dist=nd[nd[a].right].dist+1;
	return a;
}
