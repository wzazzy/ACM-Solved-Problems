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
const double eps=1e-12;
const int MAX=1e6+10;
const ll mod=1e9+7;
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator +(Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
bool operator ==(Point a,Point b){return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;}
struct Line
{  
	Point p;
	Vector v;  
	double ang;
	Line(){}
	Line(Point a,Vector b)
	{
		p=a;
		v=b;
		ang=atan2(v.y,v.x);
	}
	void twopoint(Point a,Point b)
	{
		p=a;
		v=b-a;
		ang=atan2(v.y,v.x);
	}
};
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double length(Vector a){return sqrt(dot(a,a));}
bool SegInterLine(Point a,Point b,Point c,Point d)
{
	return sgn(cross((c-b),(a-b)))*sgn(cross((d-b),(a-b)))<=0;
}
int main()
{
	int t,i,j,k,n,flag,tag,cnt;
	Line l[111];
	Point p[222];
	double d1,d2;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			cnt=0;
			for(i=0;i<n;i++)
			{
				p[cnt++].input();
				p[cnt].input();
				l[i].twopoint(p[cnt-1],p[cnt]);
				cnt++;
			}
			if(n==1||n==2)
			{
				puts("Yes!");
				continue;
			}
			flag=0;
			for(i=0;i<cnt&&!flag;i++)
			{
				for(j=i+1;j<cnt&&!flag;j++)
				{
					if(p[i]==p[j]) continue;
					tag=0;
					for(k=0;k<n;k++)
					{
						if(!SegInterLine(p[i],p[j],l[k].p,l[k].p+l[k].v))
						{
							tag=1;
							break;
						}
					}
					if(!tag) flag=1;
				}
			}
			if(flag) puts("Yes!");
			else puts("No!");
		}
	}
	return 0;
}