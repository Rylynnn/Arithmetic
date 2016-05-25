void topo()
{
    //priority_queue<int,vector<int>,cmp> q;  //µ„”––Ú ± 
    for(int i=1;i<=n;i++)
      if(in[i]==0) q.push(i);
    int flag=0;
    while(!q.empty())
    {
		int x=q.top();
        q.pop();
        ans[++num]=x;
        for(int i=0;i<way[x].size();i++)
        {
            in[way[x][i]]--;
            if(in[way[x][i]]==0)
            q.push(way[x][i]);
        }
    }
}

