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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int flag,ans;
	double h,u,d,f,sum,t;
	while(cin>>h>>u>>d>>f&&h)
	{
		ans=flag=0;
		sum=0;
		t=u*f/100;
		while(1)
		{
			ans++;
			if(u>0) sum+=u;
			if(sum>h)
			{
				flag=1;
				break;
			}
			u-=t;
			sum-=d;
			if(sum<0) break;
		}
		if(flag) printf("success on day %d\n",ans);
		else printf("failure on day %d\n",ans);
	}
    return 0;
}