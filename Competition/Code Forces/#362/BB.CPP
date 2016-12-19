#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int n,t=1,x;
	char s[300];
	scanf("%s",s);
	int len=strlen(s);
	int d=0;
	for(int i=len-1;i>0;i--)
	{
		if(s[i]=='e')
		{
			break;
		}

		d=(s[i]-'0')*t+d;
		t*=10;
	}
	if(t==100) t=2;
	else if(t==1000) t=3;
	else t=1;
	x=len-3-t;
	if(x>=d)
	{
		printf("%c",s[0]);
		for(int i=1;i<=d;i++)
		{
			printf("%c",s[i+1]);
		}
		if(x>d) printf(".");
		for(int i=d+2;i<len-1-t;i++)
			printf("%c",s[i]);
	}
	else
	{
		printf("%c",s[0]);
		for(int i=2;i<len-1-t;i++)
		{
			printf("%c",s[i]);
		}
		for(int i=1;i<=(d-x);i++) printf("0");
	}
	return 0;
}
