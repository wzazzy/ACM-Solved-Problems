////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-03 18:59:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1337
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1600KB
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
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
int main()
{
	int t,n;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			cout<<(int)sqrt(1.0*n)<<endl;
		}
	}
    return 0;
}