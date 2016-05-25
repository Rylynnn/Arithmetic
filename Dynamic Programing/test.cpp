#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int f[1005];

int main()
{
	char a[1005], b[1005];
	int i, j;
	while(scanf("%s%s", a + 1, b + 1) != EOF)
	{
		memset(f, 0, sizeof(f));
		for(i = 1; a[i] != '\0'; i++)
		{
			for(j = 1;b[j] != '\0'; j++)
			{
				if(a[i] == b[j] && f[j] == f[j - 1]) f[j]++;
				else f[j] = f[j - 1] > f[j] ? f[j - 1] : f[j];
				cout << f[j ] << endl;
			}
		}
		cout << f[j - 1] << endl;
	}
	return 0;
}
