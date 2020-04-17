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

const int N=1e5;
const int M=2e5;
const int mod=1e9+7;

void solve()
{
    int ans=0;
    int x,y,z,x1,y1,z1,a,b,c,d,e,f;
    cin>>x1>>y1>>z1>>x>>y>>z>>a>>b>>c>>d>>e>>f;

    if(x1>0)
    {
        if(x1>x) ans+=f;
    }
    else if(x1<0)
    {
        ans+=e;
    }

    if(y1>0)
    {
        if(y1>y) ans+=b;
    }
    else if(y1<0)
    {
        ans+=a;
    }

    if(z1>0)
    {
        if(z1>z) ans+=d;
    }
    else if(z1<0)
    {
        ans+=c;
    }

    cout<<ans;
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