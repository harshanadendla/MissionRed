/*
    YES PAIN YES GAIN
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+5;
const int mod=1e9+7;

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;

    int m=r-l+1;
    int cnt[4]={0,0,0,0};

    cnt[0]=cnt[1]=cnt[2]=m/3;

    if(m%3)
    {
        cnt[l%3]++;
        if((m%3)>1) cnt[(l+1)%3]++;
    }

    int dp[n+1][3];
    mem(dp,0);

    dp[1][0]=cnt[0];
    dp[1][1]=cnt[1];
    dp[1][2]=cnt[2];

    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][0]*cnt[0] + dp[i-1][1]*cnt[2] + dp[i-1][2]*cnt[1])%mod;
        dp[i][1]=(dp[i-1][0]*cnt[1] + dp[i-1][1]*cnt[0] + dp[i-1][2]*cnt[2])%mod;
        dp[i][2]=(dp[i-1][0]*cnt[2] + dp[i-1][1]*cnt[1] + dp[i-1][2]*cnt[0])%mod;
    }

    cout<<dp[n][0]%mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}