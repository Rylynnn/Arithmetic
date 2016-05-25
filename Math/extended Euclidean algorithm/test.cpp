#include <iostream>
#include <algorithm>
#include <string>
//#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
//#include <ctime>
#include <ctype.h>
using namespace std;
#define LL long long
#define inf 0x3fffffff

LL gcd (LL a, LL b)
{
	return b ? gcd (b, a%b) : a;
}

void Egcd (LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return ;
	}
	Egcd (b, a%b, x, y);
	LL tp = x;
	x = y;
	y = tp - a/b*y;
}

int main()
{
	LL xx, yy, a, b, x, y, L, n, M, N, d;
	while (~scanf ("%lld%lld%lld%lld%lld", &xx, &yy, &M, &N, &L))
	{
		a = N - M;
		b = L;
		n = xx - yy;
		d = gcd (a, b);
		if (n % d != 0)
		{
			puts ("Pat");
			continue;
		}
		a /= d;
		b /= d;
		n /= d;
		Egcd (a, b, x, y);
		x *= n;
		if (b < 0) b = -b;    //周期是正的
		x = (x % b + b) % b;
		printf ("%lld\n", x);
	}
	return 0;
}
