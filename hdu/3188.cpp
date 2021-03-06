////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-04 22:10:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3188
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1564KB
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
int main()
{
	int t,a,b,c;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==b||b==c||a==c) puts("perfect");
			else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a) puts("good");
			else puts("just a triangle");
		}
	}
	return 0;
}