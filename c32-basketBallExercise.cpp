//ummmmmmmaaaa......tried hard...vachesindi....dp sum ac in 1 go...1400 level sum ni chalasepu alochinchav
//but came with ac.....go on ...go on

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

const int N=1e5+5;
const int M=2e5;
const int mod=1e9+7;

int n;
int a[N][2];
int dp[N][2];

int go(int idx,int row)
{
    if(idx==n) return 0;

    if(dp[idx][row] != -1) return dp[idx][row];

    return dp[idx][row]=max(a[idx][1-row]+go(idx+1,1-row),go(idx+1,row));
}

void solve()
{
    mem(dp,-1);

    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i][0];
    for(int i=0;i<n;i++) cin>>a[i][1];

    cout<<max(go(0,0),go(0,1));
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