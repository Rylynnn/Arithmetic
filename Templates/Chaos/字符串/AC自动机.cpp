struct tree
{
	char ch;
	int son,next,father,danger,suffix;
};
tree a[110000];
void insert(char *s,int l,int t,int x)
{
	int i;
	if (a[x].danger) return ;
	if (a[x].son==0)
	{
		m++;
		a[x].son=m;
		a[m].father=x;
		a[m].ch=s[t];
		if (t+1==l)
			a[m].danger=1;
		else 
			insert(s,l,t+1,m);
	}
	else
	{
		i=a[x].son;
		while (1)
		{
			if (a[i].next==0||a[i].ch==s[t])
				break;
			i=a[i].next;
		}
		if (a[i].ch==s[t] && t+1==l) a[i].danger=1;
		else if (a[i].ch==s[t]) insert(s,l,t+1,i);
		else 
		{
			m++;
			a[i].next=m;
			a[m].father=x;
			a[m].ch=s[t];
			if (t+1==l) a[m].danger=1;
			else insert(s,l,t+1,m);
		}
	}
}
void build()
{
	int child(int ,char);
	int i,l,r;
	l=r=1;
	q[1]=1;
	a[1].suffix=1;
	if (a[1].son==0) return;
	while (l<=r)
	{
		if (!a[q[l]].danger)
		{
			i=a[q[l]].son;
			while (1)
			{
				r++;
				q[r]=i;
				i=a[i].next;
				if (i==0) break;
			}
			
		}
		i++;
	}
	for (i=2;i<=r;i++)
	{
		if (a[q[i]].father==1)
		{
			a[q[i]].suffix=1;
			continue;
		}
		a[q[i]].suffix=child(a[a[q[i]].father].suffix,a[q[i]].ch);
		if (a[a[q[i]].suffix].danger)
			a[q[i]].danger=1;
	}
}

int child(int x,char ch)
{
	int i
	i=a[x].son;
	while (i!=0)
	{
		if (a[i].ch==ch)  break;
		i=a[i].next;
	}
	if (i!=0) return i;
	else if (x==1) return 1;
	else return child(a[x].suffix,ch);
}
