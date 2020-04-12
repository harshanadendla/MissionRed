//doola teerchesindi...2 days blank...at last had to aurrender...understand and convince myself....from now on
//i will think in this way for dp...with sense...inkonchem neeed some more observation
//just think for a while and come up with that one required line...boom...dp is urs

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

const int N=505;
const int M=3e5;
const int mod=1e9+7;

int n;
string str;
int dp[N][N];

int go(int l,int r)
{
    if(l==r) return dp[l][r]=1;
    if(l>r) return dp[l][r]=0;
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r]=1+go(l+1,r);
    for(int i=l+1;i<=r;i++)
    {
        if(str[l]==str[i])
        {
            dp[l][r]=min(dp[l][r],go(l+1,i-1)+go(i,r));
        }
    }

    return dp[l][r];
}

void solve()
{
    mem(dp,-1);

    cin>>n>>str;
    cout<<go(0,n-1);
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