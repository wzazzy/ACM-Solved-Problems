////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-11 19:29:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2369
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:2648KB
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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int main()
{
	int m,len,l,r,tag[1111],ans;
	char a[MAX];
	while(~scanf("%d",&m)&&m)
	{
		getchar();
		gets(a);
		len=strlen(a);
		ans=0;
		mem(tag,0);
		for(l=0,r=0;r<len;r++)
		{
			if(!tag[a[r]])
			{
				if(m) m--;
				else
				{
	//				cout<<l<<" "<<r<<endl;
					ans=max(ans,r-l);
					while(1)
					{
						tag[a[l]]--;
						l++;
						if(tag[a[l-1]]==0) break;
					}
				}
			}
			tag[a[r]]++;
		}
	//	cout<<l<<" "<<r<<endl;
		ans=max(ans,r-l);
		printf("%d\n",ans);
	}
	return 0;
}