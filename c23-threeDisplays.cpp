//dp....the moment i see a bit of dp solution...i can get an ac...the problem is i m not getting the perfect oneliners

/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=3e3+5;
const int M=2e5;
const int mod=1e9+7;

int n,a[N],c[N],dp[4][N],ans;

void pre()
{
    ans=3e9+1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=3e9+1;
        }
    }
}

void solve()
{
    pre();

    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++) cin>>c[i];

    for(int i=1;i<=n;i++)
    {
        dp[1][i]=c[i];
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            {
                for(int k=2;k<=3;k++)
                {
                    dp[k][i]=min(dp[k][i],dp[k-1][j]+c[i]);
                }
            }
        }
        ans=min(ans,dp[3][i]);
    }

    (ans==3e9+1) ? cout<<-1 : cout<<ans ;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    cout << "\n\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}