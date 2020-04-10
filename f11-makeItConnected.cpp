//sontha approach ochindi..but gave wa due to minor error...gurtu pattala...ashishgup blew my mind..idi mst ani 
//gurtu pattala...sooo self occupied with my method my method ani....anyways...manchi prob

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

const int N=4e5+5;
const int M=3e5;
const int mod=1e9+7;

int n,m;
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> edges;

struct ds
{
    int id,members;
}parent[N];

int find(int u)
{
    if(u==parent[u].id) return u;
    return parent[u].id=find(parent[u].id);
}

void unioN(int x,int y)
{
    x=find(x);
    y=find(y);
    
    if(parent[x].members < parent[y].members)
    {
        parent[x].id=parent[y].id;
        parent[y].members+=parent[x].members;
    }
    else
    {
        parent[y].id=parent[x].id;
        parent[x].members+=parent[y].members;
    }
}

int mst()
{
    int ans=0,e=0;

    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
    }

    while(e<n-1)
    {
        auto edge=edges.top();
        edges.pop();

        int set1=edge.s.f;
        int set2=edge.s.s;

        if(find(set1)!=find(set2))
        {
            e++;
            ans+=edge.f;
            unioN(set1,set2);
        }
    }

    cout<<ans;
}

void solve()
{
    cin>>n>>m;

    vpii a;
    for(int i=1,w;i<=n;i++)
    {
        cin>>w;
        a.pb(mp(w,i));
    }

    sort(all(a));

    for(int i=1,u,v,w;i<a.size();i++)
    {
        u=a[0].s;
        v=a[i].s;
        w=a[0].f+a[i].f;
        edges.push(mp(w,mp(u,v)));
    }

    for(int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        edges.push(mp(w,mp(u,v)));
    }

    mst();
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