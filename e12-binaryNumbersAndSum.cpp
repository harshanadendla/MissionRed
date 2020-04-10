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

const int N=2e5+5;
const int M=3e5;
const int mod=998244353;

int two[N];

int mul(int a,int b)
{
    return ((a%mod) * (b%mod))%mod;
}

void solve()
{
    two[0]=1;
    for(int i=1;i<N;i++) two[i]=mul(two[i-1],2);

    vi idx1,idx2;
    int ans=0;

    int n,m;
    string a,b;
    cin>>n>>m;

    vi p(n+1,0);
    cin>>a;
    for(int i=0;i<n;i++)
    {
        p[n-i]=a[i]-'0';
        if(p[n-i])
        {
            idx1.pb(n-i);
        }
    }

    vi q(m+1,0);
    cin>>b;
    for(int i=0;i<m;i++)
    {
        q[m-i]=b[i]-'0';
        if(q[m-i])
        {
            idx2.pb(m-i);
        }
    }

    reverse(all(idx1));
    reverse(all(idx2));

    n=idx1.size();
    m=idx2.size();

    for(int i=0,idx,cnt;i<n;i++)
    {
        idx=upper_bound(all(idx2),idx1[i])-idx2.begin();
        cnt=m-idx+(idx2[idx-1]==idx1[i]);
        ans+=mul(cnt,two[idx1[i]-1]);
        ans%=mod;
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

    #ifndef ONLINE_JUDGE
    cout << "\n\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}