vector <int> residue(int p,int N,int a)
{
    int g=primitive_root(p);
    long long m=discrete_log(g,a,p);
    vector<int> ret;
    if (a==0)
    {
        ret.push_back(0);
        return ret;
    }
    if (m==-1) return ret;
    long long A=N,B=p-1,C=m,x,y;
    long long d=extended_gcd(A,B,x,y);
    if (c%d!=0) return ret;
    x=x*(C/d)%B;
    long long delta=B/d;
    for (int i=0;i<d;i++)
    {
        x=((x+delta)%B+B)%B;
        ret.push_back((int)pow_mod(g,x,p));
    }
    sort(ret.begin(),ret.end());
    ret.erase(unqinue(ret.begin(),ret.end()),ret.end());
    return ret;
}

