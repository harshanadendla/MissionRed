//idea ochesindi...implementation ki one day pattindi...focus...focus..and symmetric ga unnavi anni vhange cheyyali ra howle!!!

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
const int M=3e5;
const int mod=1e9+7;

int sq[N+1];

void solve()
{
    for(int i=1;i<=N;i++) sq[i]=sq[i-1]+(2*i-1);

    multiset<int> perfs,notperfs;
    int ans=0,zero=0;

    int n;
    cin>>n;

    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;

        int idx=lower_bound(sq,sq+N+1,a)-sq;

        if(sq[idx]==a)
        {
            if(a==0) zero++;
            perfs.insert(a);
        }
        else
        {
            notperfs.insert(min(abs(a-sq[idx-1]),abs(a-sq[idx])));
        }
    }

    if(zero==n)
    {
        cout<<n;
        return;
    }
    if(perfs.size()==n/2 && notperfs.size()== n/2)
    {
        cout<<"0";
        return;
    }

    if(perfs.size() > notperfs.size())
    {
        int i=perfs.size()-n/2;

        for(auto it=perfs.rbegin();i>0;i--,it++)
        {
            (*it) ? ans+=1 : ans+=2 ;
        }
    }
    else
    {
        int i=notperfs.size()-n/2;

        for(auto it=notperfs.begin();i>0;i--,it++)
        {
            ans+=(*it);
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