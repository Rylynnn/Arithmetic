//割点和桥
const int V=1000;
int edge=[V][V];
int bridge[V][V],cut[V];
int low[V],dfn[V],vis[V];

void cut_bridge(int cur,int father,int dep,int n)
{
	vis[cur]=1;
	dfn[cur]=low[cur]=dep;
	int children=0;
	for (int i=0;i<n;i++)
	  if (edge[cur][i])
	  {
			if (i!=father&&1==vis[i])
			{
				if (dfn[i]<low[cur])  low[cur]=dfn[i];
			}
			if (vis[i]==0)
			{
				cut_bridge(i,cur,dep+1,n);
				children++;
				if (low[i]<low[cur])  low[cur]=low[i];
				if ((father==-1&& children>1) || (father!=-1&&low[i]>=dfn[cur])) cut[cur]=true;
				if (low[i]>dfn[cur])
				{
					bridge[cur][i]=bridge[i][cur]=true;
				}
			}
	  }
	vis[cur]=2;
}
//双联通分量
const int maxn=1010;
vector<int> edge[maxn];
vector<vector<int>> connect;
int dfn[maxn],low[maxn],in_seq[maxn];
int stack[maxn],list[maxn];
int cnt, top,pop,len;
void biconnect (int v)
{
	stack[++top]=v;
	dfn[v]=low[v]=pop++;
	int i,succ;
	for (i=edge[v].size()-1;i>=0;i--)
	{
		succ=edge[v][i];
		if (dfn[succ]==-1)
		{
			biconnect(succ);
			if (low[succ]>=dfn[v])
			{
				cnt++;
				len=0;
				do
				{
					in_seq[stack[top]]=cnt;
					list[len++]=stack[top];
					top--;
				}while(stack[top+1]!=succ);
				in_seq[v]=cnt;
				list[len++]=v;
				vector<int> tmp(list,list+len);
				connect.push_back(tmp);
			}
			low[v]=min(low[v],low[succ]);
		}
		else low[v]=min(low[v],dfn[succ]);
	}
}
//极大强连通分量Tarjan算法
struct strongly_connected_components
{
	vector<int>&color;
	vector<int>Stack;
	int colorCnt,curr,*instack,*dfn,*low,*info,*next,*to;
	void dfs(int x)
	{
		dfn[x]=low[x]=++curr;
		Stack.push_back(x);
		instack[x]=true;
		for (int j=info[x];j;j=next[j])
		  if (!instack[to[j]])
		  {
				dfs(to[j]);
				low[x]=std::min(low[x],low[to[j]]);
		  }
		  else
		  {
				if (instack[to[j]]==1)  low[x]=std::min(low[x],dfn[to[j]]);
		  }
		if (low[x]==dfn[x])
		{
			while (Stack.back()!=x)
			{
				color[Stack.back()]=colorCnt;
				instack[Stack.back()]=2;
				Stack.pop_back();
			}
			color[Stack.back()]=colorCnt++;
			instack[Stack.back()]=2;
			Stack.pop_back();
		}
	}
	strongly_connected_components(const std::vector<std::pair<int,int>> &edgeList,int n,std::vector<int>&ans):color(ans)
	{
		color.resize(n);
		instack=new int[n];
		dfn=new int[n];
		low=new int[n];
		info=new int[n];
		next=new int[(int)edgeList.size()+5];
		to=new int[(int)edgeList.size()+5];
		std::fill_n(info,n,0);
		for (size_t i=0;i<edgeList.size();i++)
		{
			to[i+1]=edgeList[i].second;
			next[i+1]=info[edgeList[i].first];
			info[edgeList[i].first]=i+1;
		}
		std::fill_n(instack,n,0);
		colorCnt=0;
		curr=0;
		for (int i=0;i<n;i++)
		{
			if (!instack[i])  dfs(i);
		}
		delete[] instack;
		delete[] dfn;
		delete[] low;
		delete[] info;
		delete[] next;
		delete[] to;
	}
};
//拓扑排序
const int maxn=100000+5;
vector<int> g[maxn];
int du[maxn],n,m,L[maxn];

bool toposort()
{
	memset(du,0,sizeof(du));
	for (int i=0;i<n;i++)
	  for (int j=0;j<g[i].size();j++)
	    du[g[i][j]]++;
	int tot=0;
	queue<int> Q;
	for (int i=0;i<n;i++)
	  if (!du[i]) Q.push(i);
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		L[tot++]=x;
		for (int j=0;j<g[x].size();j++)
		{
			int t=g[x][j];
			du[t]--;
			if (!du[t]) Q.push(t);
		}
	}
	if (tot==n) return 1;
	return 0;
}
//2SAT

struct LogVar
{
	int index;
	bool pre;
	LogVar(int _index=0,bool _pre=false):index(_index),pre(_pre){}
};

struct BinExp
{
	LogVar p,q;
	BinExp(LogVar _p=LogVar(),LogVar _q=LogVar()): p(_p),q(_q){}
};

inline int get_value(int sol[MAXN],int n,int x)
{
	int r=x>n?x-n:x;
	if (sol[r]==-1)
	  return -1;
	return x>n?!sol[r]:sol[r];
}

void dfs(int x)
{
	low[x]=dfn[x]=++id_cnt;
	s[++top]=x;
	vis[x]=true;
	for (int i=head[x],k;i;i=h[i].next)
	  if (!vis[k=h[i].to])
	  {
			dfs(k);
			low[x]=min(low[x],low[k]);
	  }
	  else (dfn[x]==low[x])
	  {
			s[top+1]=-1;
			for (++cnt;s[top+1]!=x;--top)
			{
				c[cnt].push_back(s[top]);
				belong[s[top]]=cnt;
			}
	  }
}

inline bool two_SAT(int n,int m,BinExp a[MAXM],int sol[MAXM])
{
	edge_tot=0,id_cnt=0,cnt=0,top=0;
	for (int i=1;i<=2*n;i++)
	{
		head[i]=0;
		vis[i]=false;
		c[i].clear();
	}
	for (int i=1;i<=n;i++)
	  sol[i]=-1;
	for (int i=0;i<m;i++)
	{
		add_edge(a[i].p.index+a[i].p.pre*n,a[i].q.index+!a[i].q.pre*n);
		add_edge(a[i].q.index+a[i].q.pre*n,a[i].p.index+!a[i].p.pre*n);
	}
	for (int i=1;i<=2*n;i++)
	  if (!vis[i]) dfs(i);
	for (int i=1;i<=n;i++)
	  if (belong[i]==belong[i+n]) return false;
	for (int i=1;i<=cnt;i++)
	{
		int val=1;
		for (int j=0;j<int(c[i].size());j++)
		{
			int cur=c[i][j];
			if (get_value(sol,n,cur)==0)  val=0;
			for (int k=head[cur];k;k=h[k].next)
			  if (get_value(sol,n,h[k].to)==0) val=0;
			if (val==0) break;
		}
		for (int j=0;j<int(c[i].size());j++)
		  if (c[i][j]>n)  so[c[i][j]-n]=!val;
		           else   sol[c[i][j]]=val;
	}
	return true;
}

	
			 
		
