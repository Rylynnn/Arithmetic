#include <cstdio>
#include <iostream>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define MAX 107
using namespace std;
class Graph{
    //For i = 1 and larger, adjList[i][0] = i.
    //For j = 1 and larger, adjList[i][j] is adjacent to i.
    int Matrix[MAX][MAX];
    int n;
    int adjMatrix[MAX][MAX];
    int deg[MAX];//每个点的出度
public:
    bool judge();
    void buildGraph(int k,int m);
    void getEdgeEnds(int edgeIndex, int& row, int& col);
    int initForContract();
    int contract();
    int minCut(int nIter);
    int getNodeNum();
    friend void buildGraph(char *fname, Graph& g);
};

int Graph::getNodeNum(){
    return n;
}

void Graph::getEdgeEnds(int edgeIndex, int& row, int& col){//通过边的编号，在邻接矩阵中算出边的起始点和终止点
    int num = 0;
    for(row=1;row<=n;row++){
        if(num + deg[row] >= edgeIndex)
            break;
        num += deg[row];
    }
    for(col=1;col<=n;col++){
        num += adjMatrix[row][col];
        if(num >= edgeIndex)
            break;
    }
}
int Graph::initForContract(){//重新处理整个图的边数，并且把之前删掉的点从图中去掉
    int edgeNum = 0;
    memset(adjMatrix,0,sizeof(adjMatrix));
    for(int i=1; i<=n; i++){
        deg[i] = 0;
        for(int j=1;j<=n;j++){
            adjMatrix[i][j] = Matrix[i][j];
            deg[i]+=Matrix[i][j];
        }
        edgeNum += deg[i];
    }
    return edgeNum;
}
int Graph::contract(){
    int edgeNum = initForContract();
    srand(321547587);
    for(int iter = 0;iter < n-2; iter++){//缩点
        int edgeIndex = rand()%edgeNum+1;//随机一条边的编号
        int v1, v2;
        getEdgeEnds(edgeIndex, v1, v2);
        if(v1 > v2)
            swap(v1, v2);
        for(int i=1; i <= n; i++){//将v1和v2两点缩到v1点的位置
            if(i == v1){
                deg[v1] -= adjMatrix[v1][v2];
                edgeNum -= 2*adjMatrix[v1][v2];
                adjMatrix[v1][v2] = adjMatrix[v2][v1] = 0;
            }
            else if(adjMatrix[v2][i]){
                adjMatrix[v1][i] += adjMatrix[v2][i];
                adjMatrix[i][v1] = adjMatrix[v1][i];
                deg[v1] += adjMatrix[v2][i];
                adjMatrix[v2][i] = adjMatrix[i][v2] = 0;
            }
        }
        deg[v2] = 0;
    }
    return edgeNum/2;
}
int Graph::minCut(int nIter){
    srand(time(NULL));
    int mincut = n*n;
    for(int i=0; i<nIter; i++){
        mincut = min(mincut, contract());
    }
    return mincut;
}
void Graph::buildGraph(int k,int m){
    int a,b,c;
    n=k;
    memset(Matrix,0,sizeof(Matrix));
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&c);
        Matrix[a+1][b+1]=Matrix[b+1][a+1]=c;
    }
    memset(deg,0,sizeof(deg));
}
bool Graph::judge(){
    queue<int>h;
    int cnt=0;
    bool vis[MAX];
    memset(vis,0,sizeof(vis));
    h.push(1);
    cnt++;
    vis[1]=1;
    while(!h.empty()){
        int now=h.front();
        h.pop();
        for(int i=1;i<=n;i++){
            if(Matrix[now][i]!=0&&!vis[i]){
                h.push(i);
                vis[i]=1;
                cnt++;
            }
        }
    }
    if(cnt==n){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int k,m;

    while(scanf("%d%d",&k,&m)!=EOF){
        Graph g;
        g.buildGraph(k,m);
        bool p=g.judge();
        if(p==false){
            printf("0\n");
            continue;
        }
        int num= g.getNodeNum();
        int nIter = num*num*int(log(num*1.0));
        int mincut = g.minCut(nIter);
        //printf("%f\n",(double)(ed-st)/CLOCKS_PER_SEC);
        printf("%d\n",mincut);
    }
    return 0;
}
