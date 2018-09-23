#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
ll n,m,f[MAX];
void completepack(ll v,ll w)
{
    ll i;
    for(i=v;i<=m;i++)
      f[i]=max(f[i],f[i-v]+w);
    return;
}
void zeroonepack(ll v,ll w)
{
    ll i;
    for(i=m;i>=v;i--)
      f[i]=max(f[i],f[i-v]+w);
    return;
}
void multiplepack(ll v,ll w,ll num)
{
    if(num*v>=m)
    {
        completepack(v,w);
        return;
    }
    ll k=1;
    while(k<num)
    {
        zeroonepack(k*v,k*w);
        num-=k;
        k<<=1;
    }
    zeroonepack(num*v,num*w);
    return;
}
ll w[MAX],v[MAX],c[MAX];
int main()
{
    int i;
    while(~scanf("%lld%lld",&n,&m))
    {
		mem(f,0);
		for(i=1;i<=n;i++)
	    {
			scanf("%lld",&v[i]);
		}
		for(i=1;i<=n;i++)
	    {
			scanf("%lld",&w[i]);
		}
		for(i=1;i<=n;i++)
	    {
			scanf("%lld",&c[i]);
		}
	    for(i=1;i<=n;i++)
	    {
	        multiplepack(v[i],w[i],c[i]);
	    }
	    printf("%lld\n",f[m]);
	}
    return 0;
}