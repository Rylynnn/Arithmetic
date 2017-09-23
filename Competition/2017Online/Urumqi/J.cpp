#include"string.h"  
#include"queue"  
using namespace std;  
#define M 10007
const int inf=0x7fffffff;  
struct node  
{  
    int u,v,c,f,next;  //C为花费，F为flow流量  
}e[M];  
int pre[M],dis[M],head[M],t;  
int vis[M];  
void add1(int u,int v,int c,int f)  
{  
    e[t].u=u;  
    e[t].v=v;  
    e[t].c=c;  
    e[t].f=f;  
    e[t].next=head[u];  
    head[u]=t++;  
}  
void add(int u,int v,int c,int f)  
{  
    add1(u,v,c,f);        
    add1(v,u,-c,0);  //反向边流量初始为零，如果走反向边费用正好和原边抵消  
}  
int spfa(int s,int t)  
{  
    int i,u,v;  
    queue<int>q;  
    q.push(s);  
    memset(vis,0,sizeof(vis));  
    memset(pre,-1,sizeof(pre));  
    for(i=s;i<=t;i++)  
        dis[i]=inf;  
    dis[s]=0;  
    while(!q.empty())  
    {  
        u=q.front();  
        q.pop();  
        for(i=head[u];i!=-1;i=e[i].next)  
        {  
            v=e[i].v;  
            if(e[i].f&&dis[v]>dis[u]+e[i].c)  //找到一条最小费用流  
            {  
                dis[v]=dis[u]+e[i].c;    
                pre[v]=i;       //记录路径  
                if(!vis[v])  
                {  
                    vis[v]=1;  
                    q.push(v);  
                }  
            }  
        }  
        vis[u]=0;  
    }  
    if(dis[t]!=inf)  
        return 1;  
    return 0;  
}  
void solve(int s,int t)  
{  
    int ans=0,i,j;  
    int flow=0,cost=0;     //总流量、总费用  
    while(spfa(s,t))  
    {  
        int minf=inf;  
        for(i=pre[t];i!=-1;i=pre[e[i].u])  
        {  
            if(e[i].f<minf)  
                minf=e[i].f;  
        }  
        flow+=minf;   //该条路径的流量  
        for(i=pre[t];i!=-1;i=pre[e[i].u])  
        {  
            j=i^1;  
            e[i].f-=minf;  
            e[j].f+=minf;  
        }  
    cost+=dis[t]*minf;   //单位运费和乘以流量得费用     
    }  
    printf("%d\n",cost);  
}  
string a, b;
unordered_map<string, int> hh;
int main()
{
    int t, m, x;
	ios::sync_with_stdio(false);
    cin >> t;
	while(t--){
        cin >> m;
		hh.clear();
        int num = 1;
		t=0;  
        memset(head,-1,sizeof(head));  
		for(int i=1; i<=m; i++){
            cin >> p[i].a >> p[i].b >> p[i].x;
			if(hh[p[i].a] == 0){
                hh[p[i].a] = num++;
            }
            if(hh[p[i].b] == 0){
                hh[p[i].b] = num++;
            }
			//cout << a << h[a] << b << h[b] << endl;
    	}
        init(V);
		for(int i=1; i<=num; i++){
			add(i, i+num, 1, 0);
		}
		for(int i=1; i<=m; i++){
            add(hh[p[i].a]+num, hh[p[i].b], 1, p[i].x);
		}
        int src, dst, ans;
		string c = "Shanghai";
		string d = "Dalian";
		string e = "Xian";
		src = hh[d];
		dst = hh[c];
		add(0, hh[d], 0, 1);
		add(hh[c], num+1, 0, 1);
		ans = solve(src, dst);
		add(0, hh[c]+num, 0, 1);
		add(hh[e], num+1, 0, 1)
        ans +=solce(src, dst);
        cout << ans << endl;
	}
	return 0;
} 
