//u r proving...u r not a red coder...akkada i felt...the need of mlogn solution...ante logn time lo find chese
//datastrucutr...but still couldnt think of set
//a datastructure need not necessarily be a container of the inputs...also it can be used
//seperately to decrease time and extra calcs
//lesson:data structure can be used as a variable kind of thing...var in the sense...
//not being any container of the input

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
    set<int> st;
    int ans=0;

    int n,m;
    cin>>n>>m;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int b[m];
    for(int i=0;i<m;i++) cin>>b[i];

    for(int i=0,j=0;i<m;i++)
    {
        if(st.find(b[i]) != st.end())
        {
            st.erase(b[i]);
            ans++;
        }
        else
        {
            while(a[j]!=b[i])
            {
                st.insert(a[j]);
                j++;
            }
            ans+=(2*st.size() + 1);
            j++;
        }
    }

    cout<<ans<<"\n";
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