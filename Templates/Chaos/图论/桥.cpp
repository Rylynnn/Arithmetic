void tarjan(int x)//Cut Edge
{	int i;
	low[x]=dfn[x]=++T;
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	epar[e[i]]=((i-1)>>1)+1;
			tarjan(e[i]);
			low[x]=min(low[x],low[e[i]]);
		}
		else 
			if (epar[x]!=(((i-1)>>1)+1))
				low[x]=min(low[x],dfn[e[i]]);
	if (low[x]==dfn[x])
		cut[epar[x]]=1;
}
