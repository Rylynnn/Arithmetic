//Íþ×ô·ò²©ÞÄ
int main()
{
    double x=(1+sqrt(5.0))/2.0;
    int k,temp,n,m;
    while(scanf("%d%d",&a,&b)!=EOF&&(a+b)){
        if(a>b){
            temp = a;
            a=b;
            b=temp;
        }
        k=b-a;
        if((int)(k*x)==a)
            printf("%d\n",0);
        else{
            printf("%d\n",1);
            for(int i=1;i<=a;i++){
                n=a-i;
                m=b-i;
                k=m-n;
                if((int)(k*x)==n)
                    printf("%d %d\n",n,m);
        	}

            for(int i=b-1;i>=0;i--){
                n=a;
                m=i;
                if(n>m) swap(n,m);
                k=m-n;
                if((int)(k*x)==n)
                    printf("%d %d\n",n,m);
            }
        }
    }
    return 0;
}
//k±¶¶¯Ì¬²©ÞÄ
int a[2000000],b[2000000];
int main()
{
	int n,k;
	int T=0,cas=0;
	cin>>T;
	while (T--){
		scanf("%d %d",&n,&k);
		a[0]=b[0]=1;
		int i=0,j=0;
		while (n>a[i]){
			i++;
			a[i]=b[i-1]+1;
			while (a[j+1]*k<a[i]) j++;
			if (k*a[j]<a[i]) b[i]=b[j]+a[i];
			else b[i]=a[i];
		}
		cas++;
		printf("Case %d: ",cas);
	    if (n==a[i]) printf("lose\n");
	    else{
			int ans;
			while (n){
				if (n>=a[i]){
					n-=a[i];
					ans=a[i];
				}
				i--;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//every-SG
int main()
{
	int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        while(n--){
            int p,q,len=2,f[100];
            scanf("%d%d",&p,&q);
            if(p<q) swap(p,q);
            f[1]=p;f[2]=q;
            while(f[len]){
                f[len+1]=f[len-1]%f[len];
                len++;
            }
            int k=len-2,j=-1;
            for(int i=1;i<len-1;i++){
                if(f[i]/f[i+1]>1){
                    if(j>0&&i%2!=j%2)
                        k++;
                    j=i;
                }
            }
            ans=max(ans,k);
        }
        if(ans&1) printf("MM\n");
        else printf("GG\n");
    }
    return 0;
}
//NIM»ý
int f(int x,int y);
int g(int x,int y)
{
	if (gg[x][y]!=-1) return gg[x][y];
	if (!x) return gg[x][y]=1<<y;
	if (!y) return gg[x][y]=1<<x;
	int k=1,ans=1,t,x1=x,y1=y,x2=x,y2=y;
	while (x||y){
		t=1<<k;
		if ((x&1||y&1)&&!((x&1)&&(y&1))) ans*=t;
		k<<=1;
		x>>=1,y>>=1;
	}
	k=1;
	while (x1||y1){
		t=1<<k;
		if ((x1&1)&&(y1&1)) ans=f(ans,t/2*3);
		k<<=1;
		x1>>=1,y1>>=1;
	}
	return (gg[x2][y2]=ans);
}
int f(int x,int y)
{
	if (!x||!y) return 0;
	if (x==1) return y;
	if (y==1) return x;
	int ans=0;
	for (int i=x,k1=0;i;i>>=1,k1++)
		if (i&1) for (int j=y,k2=0;j;j>>=1,k2++)
			if (j&1) ans^=g(k1,k2);
	return ans;
}
//Anti-Nim
int n;
int main()
{
	int T;
	cin>>T;
	while (T--){
		scanf("%d",&n);
		int flag=0,s=0,j=0;
		for (int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			s^=x;
			if (x>1) flag=1;
			if (x==0) j++;
		}
		if (flag==0) if ((n-j)%2) printf("Brother\n");
						    else  printf("John\n");
		else if (s==0) printf("Brother\n");
				else   printf("John\n");
	}
	return 0;
}	
