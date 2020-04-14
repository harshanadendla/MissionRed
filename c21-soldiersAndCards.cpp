//bavundi....learnt a new technique...when checking for infinite loop slbties....go for 1e6 in linear

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

queue<int> s1,s2;

void fight()
{
    if(s1.front() > s2.front())
    {
        s1.push(s2.front());
        s1.push(s1.front());
    }
    else
    {
        s2.push(s1.front());
        s2.push(s2.front());
    }

    s1.pop();
    s2.pop();
}

void solve()
{
    int n,k1,k2;
    cin>>n;

    cin>>k1;
    for(int i=0,a;i<k1;i++)
    {
        cin>>a;
        s1.push(a);
    }

    cin>>k2;
    for(int i=0,a;i<k2;i++)
    {
        cin>>a;
        s2.push(a);
    }

    for(int steps=1;steps<=1e6;steps++)
    {
        fight();

        if(!s1.size())
        {
            cout<<steps<<" "<<2;
            return;
        }
        
        if(!s2.size())
        {
            cout<<steps<<" "<<1;
            return;
        }
    }

    cout<<"-1";
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