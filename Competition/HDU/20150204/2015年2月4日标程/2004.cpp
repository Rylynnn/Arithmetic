#include <cstdio>
#include <algorithm>
#include<fstream>
using namespace std;

const int maxn = 500000+10;
long long A[maxn],C[maxn],tot,M;

int main(){
	int n;
    while(scanf("%d",&n) == 1){
		tot = 0;
	    for(int i = 1; i <= n; i++){
			scanf("%lld",&A[i]);
			tot += A[i];
	    }
		M=tot/n;
		C[0] = 0;
		for(int i =1;i < n; i++){
			C[i] = C[i-1] + A[i] - M;
		}
		sort(C,C+n);
		long long x1 = C[n/2],ans = 0;
		for(int i = 0; i < n; i++){
			ans += abs(x1 - C[i]);
		}
		printf("%lld\n",ans);
	}
    return 0;
}
