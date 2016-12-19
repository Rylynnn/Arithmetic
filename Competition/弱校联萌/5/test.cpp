#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include<algorithm>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
#include<functional>
#include<queue>
#include<set>
#include<map>
#define LL long long
#define lp(s,i,n) for(int i = s;i < n;i++)
#define lpd(s,i,n) for(int i = s;i <= n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define scn(a)  scanf("%I64d",&a)
#define prf(a)  printf("%d\n",a)
using namespace std;
const int N = 100020;
const int MAXE = 20020;

const int INF = 0x3f3f3f3f;
const double pi = 2 * asin(1);
int cnt,pp;
int n, m;

char ch[100020];
char s[100020];

void get_next(char* p, int* next)
{
    int i, j;
    i = 0;
    j = -1;
    next[0] = -1;
    while (i < strlen(p))
    {
        if (j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            //next[i] = j;

            if (p[i] != p[j])
            next[i] = j;
            else
            next[i] = next[j];

            //cout << "next[i] = " << j << endl;
        }
        else
        {
            j = next[j];
            //cout << "i = " << i << " j = " << j << endl;
        }
    }
}
int nextt[1000020];
void index_kmp(char* p, char* x)
{
    int i = 0;
    int j = 0;
    int len1 = strlen(p);
    int len2 = strlen(x);
    int nextt[1000020];
    get_next(x, nextt);
    for (int jj = 0; jj <pp; jj++)
    {
        i = jj;
        while (i < len1 && j < len2)
        {
            if (j == 0 || p[i] == x[j])
            {
                i += pp;
                j++;
            }
            else
            {
                j = nextt[j];
                //cout << "i = " << i << " j = " << j << endl;
            }

        }

        if (j == strlen(x)) {
            cnt++; }
        j = 0;

    }
}

int main()
{

    //int next[100020];

    int t;
    cin >> t;
    lpd(1,j,t)
    {
        cnt = 0;

        clr(ch, '\0');
        clr(s, '\0');
        //clr(next, 0);
        cin >> n >> m >> pp;
        getchar();
        lp(0, i, n) {
            scanf("%c", &s[i]);
            getchar(); }

        lp(0, i, m) {
            scanf("%c", &ch[i]);
            getchar();
        }


        index_kmp(s, ch);
        printf("Case #%d: ", j);
        cout << cnt << endl;
    }
   // system("pause");
    return 0;
}
