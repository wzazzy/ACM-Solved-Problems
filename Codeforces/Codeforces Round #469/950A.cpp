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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int a,b,c,ans,t;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		ans=min(a,b);
		a-=ans;
		b-=ans;
		ans*=2;
		while(c)
		{
			if(!a&&!b) break;
			if(!a)
			{
				t=min(b,c);
				ans+=t*2;
				c-=t;
				b-=t;
			}
			else if(!b)
			{
				t=min(a,c);
				ans+=t*2;
				c-=t;
				a-=t;
			}
		}
		ans+=c/2*2;
		printf("%d\n",ans);
	}
	return 0;
}