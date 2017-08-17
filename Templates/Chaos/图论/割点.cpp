void tarjan(int x,int par)//BCC & Cut Vertex
{	int i,dc=0;
	dfn[x]=low[x]=++T;
	st.push(x);
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	++dc;
			tarjan(e[i],x);
			low[x]=min(low[x],low[e[i]]);
			if (low[e[i]]>=dfn[x])
			{	cut[x]=1;
				++bcn;
				while (!st.empty()&&st.top()!=e[i])
				{	bcc[bcn].push_back(st.top());
					st.pop();
				}
				bcc[bcn].push_back(e[i]);
				st.pop();
				bcc[bcn].push_back(x);
			}
		}
		else low[x]=min(low[x],dfn[e[i]]);
	if (par==0&&dc==1)
		cut[x]=0;
}
