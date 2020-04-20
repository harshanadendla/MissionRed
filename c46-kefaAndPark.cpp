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

int n,m;
vi graph[N];
int cat[N],ans;
bool vis[N];

void dfs(int u,int p,int maxHere,int maxC)
{
    vis[u]=true;

    if(!cat[u])
    {
        maxC=max(maxC,maxHere);
        maxHere=0;
    }
    else
    {
        maxHere++;
        maxC=max(maxC,maxHere);
    }

    if(graph[u].size()==1 && maxC<=m && p!=0) ans++;

    for(int v : graph[u])
    {
        if(v==p) continue;

        if(!vis[v])
        {
            dfs(v,u,maxHere,maxC);
        }
    }
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>cat[i];
    }

    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,0,0,0);

    cout<<ans;
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