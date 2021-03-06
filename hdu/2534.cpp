////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 10:02:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2534
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1572KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
ll gcd(ll x,ll y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)&&(a+b))
    {
		if(gcd(a,b)!=1) puts("Inf");
		else printf("%lld\n",a*b-a-b);
	}
    return 0;
}