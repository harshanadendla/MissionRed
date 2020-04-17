//asalu...simple sum ni...conditions and edges check cheukunda..got 2 was...cha..tappadu...aa snippet rayalsinde\_/
//but gudboy..idea ventane vachindi...gud

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
const int M=2e5;
const int mod=1e9+7;

vi graph[N];
vector<bool> vis(N);
int leaves[N];

void dfs(int u)
{
    vis[u]=true;

    if(u!=1 && graph[u].size()==1) leaves[u]++;

    for(int v : graph[u])
    {
        if(!vis[v])
        {
            dfs(v);
            leaves[u]+=leaves[v];
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    if(n==1)
    {
        cout<<"1";
        return;
    }

    for(int i=2,a;i<=n;i++)
    {
        cin>>a;
        
        graph[i].pb(a);
        graph[a].pb(i);
    }

    dfs(1);

    sort(leaves+1,leaves+n+1);

    for(int i=1;i<=n;i++) cout<<leaves[i]<<" ";
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

    return 0;
}