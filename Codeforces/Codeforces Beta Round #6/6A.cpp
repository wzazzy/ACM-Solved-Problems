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
const int MAX=100+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int a[5],flag,i,j,k;
	while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]))
	{
		flag=INF;
		sort(a,a+4);
		for(i=0;i<4;i++)
		{
			for(j=i+1;j<4;j++)
			{
				for(k=j+1;k<4;k++)
				{
					if(a[i]+a[j]>a[k]&&a[i]-a[j]<a[k]) flag=min(flag,1);
					else if(a[i]+a[j]>=a[k]&&a[i]-a[j]<=a[k]) flag=min(flag,2);
				}
			}
		}
		if(flag==INF) puts("IMPOSSIBLE");
		else if(flag==2) puts("SEGMENT");
		else if(flag==1) puts("TRIANGLE");
	}
	return 0;
}