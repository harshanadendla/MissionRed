//logic dorikindi...but...details neglect chesa...no....dint think like a red coder..
//do not forget invalid operations

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
    vector<char> st;
    int ans=0;
    map<int,int> m;

    int n;
    cin>>n;

    string str;
    for(int i=0,val;i<n;i++)
    {
        st.clear();
        cin>>str;

        val=0;
        for(char c : str)
        {
            if(c=='(')
            {
                st.pb(c);
                val++;
            }
            else
            {
                if(st.empty() || st.back()==')')
                {
                    st.pb(c);
                }
                else
                {
                    st.pop_back();
                }
                val--;
            }
        }

        if(val==0)
        {
            if(st.empty()) m[val]++;
        }
        else
        {
            if(st.front() == st.back()) m[val]++;
        }
    }

    for(auto x : m)
    {
        if(x.f==0)
        {
            ans+=x.s/2;
            m[x.f]=0;
        }
        else
        {
            if(m[x.f] < m[-x.f])
            {
                ans+=m[x.f];
                m[x.f]=0;
            }
            else
            {
                ans+=m[-x.f];
                m[-x.f]=0;
            }
        }
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