/*
    YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
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
const int M=3e5;
const int mod=1e9+7;

void solve()
{
    int n;
    cin>>n;
    
    deque<int> d;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    sort(all(a));

    for(int i=0;i<n;i++) (i%2==0) ? d.push_front(a[i]) : d.push_back(a[i]) ;

    while(d.size())
    {
        cout<<d.front()<<" ";
        d.pop_front();
    }   
}

----------------------------------------OR----------------------------------------------------

void solve()
{
    int n;
    cin>>n;
    
    vi a(n),l,r;
    for(int i=0;i<n;i++) cin>>a[i];
 
    sort(all(a));
 
    for(int i=0;i<n;i++) (i%2) ? l.pb(a[i]) : r.pb(a[i]) ;
    reverse(all(r));
 
    for(int i : l) cout<<i<<" ";
    for(int i : r) cout<<i<<" ";
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