//superb sum...queries can also be sorted and answered as per our convinience
//yet another gud problem on rbTree
//getting to know rbTree well

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
const int mod=1e9+7;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    vpii b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i].f=a[i];
        b[i].s=i;
    }

    sort(all(b),[](pii p,pii q)
                {
                    if(p.f==q.f) return p.s<q.s;
                    return p.f>q.f;
                });
    
    int m;
    cin>>m;
    vector<pair<pii,int>> qrs(m);
    for(int i=0;i<m;i++)
    {
        cin>>qrs[i].f.f>>qrs[i].f.s;
        qrs[i].s=i;
    }

    sort(all(qrs));

    int len=0;
    int ans[m];
    rbTree<int> tree;
    for(int i=0;i<m;i++)
    {
        while(len<qrs[i].f.f) tree.insert(b[len++].s);
        ans[qrs[i].s]=a[*tree.find_by_order(qrs[i].f.s-1)];
    }

    for(int i=0;i<m;i++) cout<<ans[i]<<"\n";
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