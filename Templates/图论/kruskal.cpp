struct Edge
{
	int start,end;
	double length;
	bool visit;
}edge[MAXN*MAXN];
double kruskal(int n)
{
	int i,j=0;
	double sum=0;
	for (i=0;i<n;i++) father[i]=i;
	sort(edge,edge+Count,cmp);
	for (i=0;i<Count&&j<n;i++)
	{
		if (Union(edge[i].start,edge[i].end))
		{
			sum+=edge[i].length;
			edge[i].visit=1;
			j++;
		}
	}
	return sum;
}
