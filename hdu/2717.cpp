////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 21:28:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2717
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2584KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int flag[MAX];
void bfs(int a,int b)
{
	int t,next;
	queue<int>q;
	q.push(a);
	flag[a]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t==b) break;
		next=t+1;
		if(next>=0&&next<MAX&&!flag[next])
		{
			q.push(next);
			flag[next]=flag[t]+1;
		}
		next=t*2;
		if(next>=0&&next<MAX&&!flag[next])
		{
			q.push(next);
			flag[next]=flag[t]+1;
		}
		next=t-1;
		if(next>=0&&next<MAX&&!flag[next])
		{
			q.push(next);
			flag[next]=flag[t]+1;
		}
	}
}
int main()
{ 
	int n,k,i;
	while(cin>>n>>k)
	{
		mem(flag,0);
		bfs(n,k);
		cout<<flag[k]-1<<endl;
	}
    return 0;
}
