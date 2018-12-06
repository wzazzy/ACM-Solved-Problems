#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN=3e5+10;
struct node
{
    int l,r,p;
    node(){}
    node(int _l,int _r,int _p):l(_l),r(_r),p(_p){}
};
node que[MAXN];
int n,k,a[MAXN],num[MAXN];
ll sum[MAXN],dp[MAXN];

ll calc(int i,int j)
{
    return sum[i]+sum[j]-sum[(i+j)>>1]-sum[(i+j+1)>>1];
}

bool cmp(int i,int j,int k)
{
    ll v1=dp[i]+calc(i,k),v2=dp[j]+calc(j,k);
    if (v1==v2) return num[i]<=num[j];
    else return v1<v2;
}

int find(node cur,int i)
{
    int l=cur.l,r=cur.r+1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (cmp(i,cur.p,mid)) r=mid;
        else l=mid+1;
    }
    return r;
}

int solve(ll mid)
{
    int s=1,t=1;
    que[1]=node(1,n,0);
    dp[0]=num[0]=0;
    for (int i=1;i<=n;i++)
    {
        while(s<=t&&que[s].r<i) s++;
        dp[i]=dp[que[s].p]+calc(que[s].p,i)+mid;
        num[i]=num[que[s].p]+1;
        if (cmp(i,que[t].p,n))
        {
            while (s<=t&&cmp(i,que[t].p,que[t].l)) t--;
            if (s>t) que[++t]=node(i+1,n,i);
            else 
            {
                int pos=find(que[t],i);
                que[t].r=pos-1;
                que[++t]=node(pos,n,i);
            }
        }
    }
    return num[n];
}

int main()
{
    scanf("%d%d",&n,&k);
    sum[0]=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    ll l=0,r=sum[n]+100,ans;
    while (l<r)
    {
        ll mid=(l+r)>>1;
        if (solve(mid)<=k) r=mid,ans=dp[n]-mid*k;
        else l=mid+1;
    }
    printf("%lld\n",ans);
}
