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

int n,k,p[N];
set<int> st;

void pre()
{
    int i=1;
    p[0]=1;
    while(1)
    {
        int temp=p[i-1]*k;
        if(temp<=1e18) p[i]=p[i-1]*k;
        else break;
        i++;
    }
}

void calc(int a)
{
    int m=ceil(log(a)/log(k));
    for(int i=m;i>=0;i--)
    {
        if(a>=p[i])
        {
            st.insert(i);
            a-=p[i];
        }
    }
}

void solve()
{
    st.clear();
    
    cin>>n>>k;

    pre();

    int sum=0;
    for(int i=0,a;i<n;i++)
    {
        cin>>a;
        if(a) calc(a);
        sum+=a;
    }

    int res=0;
    for(int i : st) res+=p[i];

    (sum==res) ? cout<<"YES\n" : cout<<"NO\n" ;
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
    cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    cout << "\n\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}