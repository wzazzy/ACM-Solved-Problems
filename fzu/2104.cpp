#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int n,l,r,t,sum,i;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&n,&l,&r);
			if(n<l)
			{
				puts("0");
				continue;
			}
			if(n==l)
			{
				puts("1");
				continue;
			}
			sum=0;
			for(i=l;i<=r;i++)
			{
				sum+=n/i;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}