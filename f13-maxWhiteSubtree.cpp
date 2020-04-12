//wah..thop sum...learnt rerooting....a subtree which involves this vrtex annadu ante...it means...we need to root every
//vertex..only then we get to know all the subtrees this vertex is involved.....deenne rerooting antaru
//first.....do a general dfs...and update dif[] of each node....add max(0,dif[all its childre])...this way fill dif[]
//dif[] is purely 1 based...so we only have the max dif of all subtrees 1 is involved.....if a subtree brings >0
//simply add...else add 0ll.....once we finidh this initilal dfs....we have two things in our hand
//1)max dif in all subtrees in which 1 is involved
//2)max dif in all other vertex-rooted subtrees....these involve only children of all other verteices..except their parents
//now
//look in this way....lhs and rhs...lhs ante...entire side of the graph...where only a particular vertex and its
//children are presesnt(only children means...not its parent from which it comes in the dfs tree)
//rhs is the parent side....we have already calculated the lhs part in the very first dfs and stored things in dif[]
//now we need to calculte and add the rhs part of every vertex
//just think what is the rhs part...?
//initially in dif[parent]...dif[u] is also added...which is now updated as dp[parent] and dp[u]....
//so now...remove dif[u] from dp[p]...and add dp[p] to dp[u]...thats it.....this is just the same thing in normal
//dfs you do....and continue...last ki print dp[]

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

const int N=1e5;
const int M=2e5;
const int mod=1e9+7;

bool color[M];
int dp[M],dif[M];
vi graph[M];

void dfs(int u,int p)
{
    dif[u] = color[u] ? 1 : -1 ;

    for(int v : graph[u])
    {
        if(v==p) continue;
        dfs(v,u);
        dif[u]+=max(0ll,dif[v]);
    }
}

void reroot(int u,int p)
{
    dp[u]=dif[u];

    if(u != 1)
    {
        dp[u] += max(0ll,dp[p]-max(0ll,dif[u]));
    }

    for(int v : graph[u])
    {
        if(v==p) continue;
        reroot(v,u);
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>color[i];
    }

    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,1);
    reroot(1,1);

    for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
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