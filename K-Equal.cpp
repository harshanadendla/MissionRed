#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,k,ans=LLONG_MAX;
    cin>>n>>k;

    int a[n],sum[n];

    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        sum[i]=a[i];
        if(i) sum[i]+=sum[i-1];
    }

    for(int i=0,j=0;i<n;i=j)
    {
        while(j<n && a[j]==a[i]) j++;
        int cnt=j-i , x=a[i] , l_cnt=i*(x-1) - (i!=0)*sum[i-1] , r_cnt=sum[n-1]-sum[j-1]-(n-j)*(x+1);
        if(cnt>=k) ans=0;
        if(cnt+i>=k) ans=min(ans,l_cnt+k-cnt);
        if(cnt+n-j>=k) ans=min(ans,r_cnt+k-cnt);
        ans=min(ans,l_cnt+r_cnt+k-cnt);
    }

    cout<<max(ans,0ll);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}