//ummmmmaaa.....ac in 1 go

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
    vi ans;

    int n,s;
    cin>>n>>s;

    if(s==0)
    {
        if(n==1)
        {
            cout<<"0 0";
            return;
        }
        else
        {
            cout<<"-1 -1";
            return;
        }
    }

    if(s>9*n)
    {
        cout<<"-1 -1";
        return;
    }

    int cnt=s/9;
    int rem=s%9;

    if(n==cnt)
    {
        for(int i=0;i<cnt;i++) cout<<"9";
        cout<<" ";
        for(int i=0;i<cnt;i++) cout<<"9";
        return;
    }

    if(n==cnt+1 && s%9)
    {
        cout<<rem;
        for(int i=0;i<cnt;i++) cout<<"9";
        cout<<" ";
        for(int i=0;i<cnt;i++) cout<<"9";
        cout<<rem;
        return;
    }

    for(int i=0;i<cnt;i++) ans.pb(9);

    ans.pb(rem);

    for(int i=0;i<n-cnt-1;i++)
    {
        ans.pb(0);
    }

    reverse(all(ans));

    cout<<"1";
    if(s%9)
    {
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]==0 || ans[i]==9)
            {
                cout<<ans[i];
            }
            else
            {
                cout<<ans[i]-1;
            }
        }
    }
    else
    {
        bool flag=true;
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]==0)
            {
                cout<<ans[i];
                continue;
            }
            if(ans[i]==9 && flag)
            {
                cout<<"8";
                flag=false;
                continue;
            }
            cout<<"9";
        }
    }

    cout<<" ";

    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
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