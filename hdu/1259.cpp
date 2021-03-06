////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 15:31:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1259
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1588KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
	int t,n,ans[11],i,a,b;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			mem(ans,0);
			ans[2]=1;
			while(n--)
			{
				cin>>a>>b;
				swap(ans[a],ans[b]);
			}
			for(i=1;i<=7;i++)
			{
				if(ans[i])
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}