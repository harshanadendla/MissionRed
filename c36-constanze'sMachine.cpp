//cheppudebba.....gattiga tagilindi....malli malli ade avutondi...not thinking those extra ew minutes...that is
//what makes all the difference...came until 2 3 5 and didn't recognize this as fib

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

int mul(int a,int b) 
{
    return ((a%mod)*(b%mod))%mod;
}

void solve()
{
    string str;
    cin>>str;

    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='m' || str[i]=='w')
        {
            cout<<"0";
            return;
        }
    }

    int ans=1;

    vi fib(n+1,0);

    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=n;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;

    for(int i=0,j,len;i<n;i=j)
    {
        j=i;
        while(j<n && str[i]==str[j]) j++;
        if(str[i]=='u' || str[i]=='n') ans=mul(ans,fib[j-i]);
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