//chinna edge case chooskola....costed 4WA's

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

void solve()
{
    int n,k;
    cin>>n>>k;


    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==1)
    {
        cout<<a[0]+k;
        return;
    }

    sort(a,a+n);

    vi dif;
    for(int i=n/2;i<n;i++) dif.pb(a[i]);

    vi v;
    for(int i=1;i<dif.size();i++) v.pb((dif[i]-dif[i-1])*i);

    for(int i=1;i<v.size();i++) v[i]+=v[i-1];

    int idx=prev(upper_bound(all(v),k))-v.begin();

    if(idx!=-1) k-=v[idx];

    cout<<dif[idx+1]+(k/(idx+2));
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