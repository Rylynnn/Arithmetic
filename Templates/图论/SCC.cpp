void tarjan(int x)//SCC
{	int i;
	dfn[x]=low[x]=++T;
	st.push(x);
	instack[x]=1;
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	tarjan(e[i]);
			low[x]=min(low[x],low[e[i]]);
		}
		else 
			if (instack[e[i]])
				low[x]=min(low[x],dfn[e[i]]);
	if (low[x]==dfn[x])
	{	++scc_cnt;
		while (!st.empty()&&st.top()!=x)
		{	scc[st.top()]=scc_cnt;
			instack[st.top()]=0;
			st.pop();
		}
		st.pop();
		scc[x]=scc_cnt;
		instack[x]=0;
	}
}
