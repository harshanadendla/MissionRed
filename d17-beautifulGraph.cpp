//overaction...pedda RED coder laga buildup...setMems ani seperate function..bokka...dani valla....5 tles...thu
//ponle..idea ventane..vachindi..santhoshinchu....thu
//p[] and mul are always a gud idea

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

const int N=3e5+5;
const int M=2e5;
const int mod=998244353;

bool flag;
int ans,res,thisComp;
int p[N];
int col[N];
vi graph[N];

int mul(int a,int b)
{
    return ((a%mod)*(b%mod))%mod;
}

void pre()
{
    p[0]=1;
    for(int i=1;i<N;i++) p[i]=mul(p[i-1],2);
}

void dfs(int u,int p)
{
    thisComp++;
    if(col[u]) res++;

    for(int v : graph[u])
    {
        if(v==p) continue;
        if(col[v]==-1)
        {
            col[v]=1-col[u];
            dfs(v,u);
            if(!flag) return;
        }

        if(col[v]==col[u])
        {
            cout<<"0\n";
            flag=false;
            return;
        }
    }
}

void solve()
{
    flag=true;
    ans=1;
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        graph[i].clear();
        col[i]=-1;
    }

    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for(int i=1;i<=n && flag;i++)
    {
        if(col[i]==-1)
        {
            thisComp=0;
            res=0;
            col[i]=1;
            dfs(i,i);
            ans*=(p[res]+p[thisComp-res])%mod;
            ans%=mod;
        }
    }

    if(flag) cout<<ans<<"\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    pre();

    int t=1;
    cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}