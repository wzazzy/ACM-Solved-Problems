////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-11-12 00:19:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1033
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int i,len,pos,x,y;
	char s[205]; 
	int dir[4][2]={10,0,0,10,-10,0,0,-10};
	while(~scanf("%s",s))
	{
		len=strlen(s);
		x=300;
		y=420; 
		pos=0;
		puts("300 420 moveto");
		for(i=0;i<len;i++)
		{
			x+=dir[pos][0];
			y+=dir[pos][1];
			printf("%d %d lineto\n",x,y);
			if(s[i]=='A') pos--;
			else pos++;
			pos=(pos+4)%4;
		}
		x+=dir[pos][0];
		y+=dir[pos][1];
		printf("%d %d lineto\n",x,y);
		puts("stroke");
		puts("showpage");
	}
	return 0;
}