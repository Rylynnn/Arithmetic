inline vector<double> operator * (vector<double> a, double b)
{
	int N=a.size();
	vector<double>  res(N,0);
	for (int i=0;i<N;i++)
	  res[i]=a[i]*b[i];
	return res;
}
inline vector<double> operator - (vector<double> a,vector<double> b)
{
	int N=a.size();
	vector<double> res(N,0);
	for (int i=0;i<N;i++)
	  res[i]=a[i]-b[i];
	return res;
}
inline void inverse(vector<double> A[], vector<double> C[],int N)
{
	for (int i=0;i<N;i++)
	  C[i]=vector<double>(N,0);
	for (int i=0;i<N;i++)
	  C[i][i]=1;
	for (int i=0;i<N;i++)
	{
		for (int j=i;j<N;j++)
		  if (fabs(A[j][i]>0)
		  {
				swap(A[i],A[j]);
				swap(C[i],C[j]);
				break;
		  }
		C[i]=C[i]*(1/A[i][i]);
		A[i]=A[i]*(1/A[i][i]);
		for (int j=0;j<N;j++)
		  if (j!=i&&fabs(A[j][i]>0))
		  {
				C[j]=C[j]-C[i]*A[j][i];
				A[j]=A[j]-A[i]*A[j][i];
		  }
    }
} 
