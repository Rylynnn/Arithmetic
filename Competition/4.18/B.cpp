#include <cstdio>
#include <cstdlib>

int main()
{
	int n;
	char s[20];
	scanf("%d", &n);
	int sum = 0, op = 0;
	for(; n--;)
	{
		int num;
                op=0;
		scanf("%s %d", s, &num);
		if(s[0] == 'A')
		{
			for(int i = 1; i <= 100; i++)
			{
				if(i + num >= 0)
					op++;
			}
		}
		else if(s[0] == 'S')
		{
			for(int i = 1; i <= 100; i++)
			{
				if(i - num >= 0)
					op++;
			}
		}
		else if(s[0] == 'D')
		{
			for(int i = 1; i <= 100; i++)
			{
				if(i / num > 0 && i % num == 0)
					op++;
			}
		}
		else if(s[0] == 'M')
		{
			for(int i = 1; i<= 100; i++)
			{
				if(i * num >= 0)
					op++;
			}
		}
		sum += 100 - op;
	}
	printf("%d\n", sum);

	return 0;
}
