//AC in 1 go....same prev sum logic anduvalla

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
    set<int> ans;
    int n;
    cin>>n;

    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans.insert(a[i]);
    }

    if(ans.size()==n)
    {
        cout<<n;
        return ;
    }

    ans.clear();
    sort(r_all(a));

    a[0]++;
    ans.insert(a[0]);
    for(int i=1;i<n;i++)
    {
        int dif=a[i-1]-a[i];

        if(dif>1)
        {
            a[i]++;
        }
        else if(dif<=0)
        {
            a[i]=max(1ll,a[i]-1);
        }

        ans.insert(a[i]);
    }

    cout<<ans.size();
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