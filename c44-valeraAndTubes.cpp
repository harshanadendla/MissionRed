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
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    vpii ans;
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                ans.pb(mp(i,j));
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                ans.pb(mp(i,j));
            }
        }
    }

    for(int i=1;i<2*(k-1);i+=2)
    {
        cout<<"2 "<<ans[i-1].f<<" "<<ans[i-1].s<<" "<<ans[i].f<<" "<<ans[i].s<<"\n";
    }
    
    cout<<n*m-2*k+2<<" ";
    for(int i=2*(k-1);i<n*m;i++)
    {
        cout<<ans[i].f<<" "<<ans[i].s<<" ";
    }
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