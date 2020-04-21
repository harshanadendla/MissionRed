/*
    YES PAIN YES GAIN
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==1)
    {
        cout<<a[0]<<"\n";
        return;
    }

    int sum=0;

    int p=-1;
    int ne=LLONG_MIN;

    bool flag;
    if(a[0]<0)
    {
        flag=false;
        ne=a[0];
    }
    else 
    {
        flag=true;
        p=a[0];
    }

    int i=1;
    while(i<n)
    {
        if(flag)
        {
            while(i<n && a[i]>0)
            {
                p=max(a[i],p);
                i++;
            }
            sum+=p;
            p=-1;
            ne=LLONG_MIN;
            flag=false;
        }
        else
        {
            while(i<n && a[i]<0)
            {
                ne=max(a[i],ne);
                i++;
            }
            sum+=ne;
            p=-1;
            ne=LLONG_MIN;
            flag=true;
        }
    }

    cout<<sum<<"\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
