/*************************************************************************
    > File Name: test.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月18日 星期五 16时18分44秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 10000007
using namespace std;
int check[10000007], prime[100007];
void getprime()
{
  	memset(check, 0, sizeof(check));
  	memset(prime, 0, sizeof(prime));
  	int tot = 1;
 	check[1] = 1;
	for(int i=2; i<=N; i++){
      	if(!check[i]){
        	check[i] = 1;
          	if(tot > 10000){break;}
          	prime[tot++] = i;
        	for(int j=i; j<=N; j+=i){
              	check[j] = 1;
            }
        }
    }
  	return;
}
int main()
{
	getprime();
  	int n;
  	while(scanf("%d", &n)!=EOF){
      	printf("%d", prime[n]);
    }
  	return 0;
}
