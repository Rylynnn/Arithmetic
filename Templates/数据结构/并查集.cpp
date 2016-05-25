int find(int x)
{
	if (father[x]==x) return x;
	father[x]=find(father[x]);
	return father[x];
}
bool Union(int x,int y)
{
	int f1=find(x);
	int f2=find(y);
	if (f1==f2) return false;
	if (f1<f2) father[f1]=f2;
	    else   father[f2]=f1;
	return true;
}
