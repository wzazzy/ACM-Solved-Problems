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
const int MAX=100000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
struct point
{
	double x,y;
	point(){}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
	point(double a,double b)
	{
		x=a;
		y=b;
	}
	double operator ^(const point &b)const
	{
		return x*b.y-b.x*y;
	}
	double operator *(const point &b)const
	{
		return x*b.x+y*b.y;
	}
	point operator -(const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
};
struct line
{
	point s,e;
	void input()
	{
		s.input();
		e.input();
	}
}l[MAX];
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;
	else return -1;
}
bool inter(line a,line b)
{
	return
	max(a.s.x,a.e.x)>=min(b.s.x,b.e.x)&&
	max(b.s.x,b.e.x)>=min(a.s.x,a.e.x)&&
	max(a.s.y,a.e.y)>=min(b.s.y,b.e.y)&&
	max(b.s.y,b.e.y)>=min(a.s.y,a.e.y)&&
	sgn((b.s-a.e)^(a.s-a.e))*sgn((b.e-a.e)^(a.s-a.e))<=0&&
	sgn((a.s-b.e)^(b.s-b.e))*sgn((a.e-b.e)^(b.s-b.e))<=0;
}
int main()
{
	int n,i,j,flag,tag;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			l[i].input();
		}
		tag=flag=0;
		printf("Top sticks:");
		for(i=1;i<=n;i++)
		{
			flag=1;
			for(j=i+1;j<=n;j++)
			{
				if(inter(l[i],l[j]))
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				if(tag) printf(",");
				tag=1;
				printf(" %d",i);
			}
		}
		puts(".");
	}
	return 0;
}