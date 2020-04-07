//simple ga alochinchu....point antha aa ichina union order lo undi
//u should take advantage of it.....if that particular union/removal of kittens is psbl....aa two kittens
//adj ga unnayani...adj means not nnecessarily next to each other...rather pressent in adj disjoint sets...anthe
//so adi left unda...right unda anavasaram.....since we are asked to print any one of the psbl orders...
//well consider any one..left/ryt...nee ishtam ill consider ryt...so
//NO BIG CHANGES AT ALL
//just union method lo....normal ga how we do itself is enough
//just add one more small step...update parent of lesser-rank ds to parent of greater-rank ds...and...and..and
//push all the children of lesser-rank ds to the vector of greater-rank ds
//ikkada no need to check any order...refer points 1 2 3 again
//last ki since all the nodes will turn into one big dsu....just find the parent of any of the nodes....
//parent of all the nodes will be same...endukante just only one single dsu
//now print all its children...anthe

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

const int N=1.5e5;
const int M=3e5;
const int mod=1e9+7;

struct DSU
{
    int id,members;
    vi children;
}parent[N];

int find(int n)
{
    if(n==parent[n].id) return n;
    return parent[n].id=find(parent[n].id);
}

void unioN(int a,int b)
{
    a=find(a);
    b=find(b);
   
    if(parent[a].members<parent[b].members) swap(a,b);

    parent[b].id=parent[a].id;
    parent[a].members+=parent[b].members;
    for(int child : parent[b].children) parent[a].children.pb(child);
}

void solve()
{
    int n,a,b;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        parent[i].id=i;
        parent[i].members=1;
        parent[i].children.pb(i);
    }

    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        unioN(a,b);
    }

    for(int child : parent[find(1)].children) cout<<child<<" ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    clock_t t1,t2;
    t1=clock();

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    t2=clock();
    cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
    #endif

    return 0;
}