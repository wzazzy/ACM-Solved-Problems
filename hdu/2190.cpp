////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 13:15:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2190
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
//////////////////System Comment End//////////////////
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
const int MAX=1000000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int sum[MAX];
int main()
{
	ll n,t,i,ans[33];
	mem(ans,0);
	ans[1]=1;
	ans[2]=3;
	for(i=3;i<=30;i++)
	{
		ans[i]=ans[i-1]+2*ans[i-2];
	}
	while(~scanf("%I64d",&t))
	{
		while(t--)
		{
			scanf("%I64d",&n);
			printf("%I64d\n",ans[n]);
		}
	}
	return 0;
}