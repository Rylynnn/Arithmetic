#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
map<int,int> S;
string s;
int num,x;
int n;
string ans[1100000];
int ansx[1100000];
int way;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (s=="insert")
		{
			cin>>x;
			S[x]++;
			q.push(x);
			way++;
			ans[way]=s;
			ansx[way]=x;
		}
		if (s=="removeMin")
		{
			if (q.empty())
			{
				way++;
				ans[way]="insert";
				ansx[way]=1;
				way++;
				ans[way]=s;
			}
			else
			{
				S[q.top()]--;
				q.pop();
				way++;
				ans[way]=s;
			}
		}
		if (s=="getMin")
		{
			cin>>x;
			if (S[x]!=0)
			{
				while (q.top()!=x)
				{
					S[q.top()]--;
					way++;
					ans[way]="removeMin";
					q.pop();
				}
				way++;
				ans[way]=s;
				ansx[way]=x;
			}
			else
			{
				way++;
				ans[way]="insert";
				ansx[way]=x;
				S[x]++;
				//cout<<q.top()<<endl;
				q.push(x);
				//cout<<q.top()<<endl;
				while (q.top()!=x)
				{
					S[q.top()]--;
					way++;
					ans[way]="removeMin";
					q.pop();
				}
				way++;
				ans[way]=s;
				ansx[way]=x;
			}
		}
	}
	cout<<way<<endl;
	for (int i=1;i<=way;i++)
	{
		cout<<ans[i];
		if (ans[i]!="removeMin")
		{
			cout<<" "<<ansx[i];
		}
		cout<<endl;
	}
	return 0;
}
