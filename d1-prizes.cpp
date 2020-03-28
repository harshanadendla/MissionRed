#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

int cost[5],p[5];

void solve()
{
    int n,ans=0;
    cin>>n;

    int a[n];

    mem(p,0);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<5;i++) cin>>cost[i];

    for(int i=0;i<n;i++)
    {
        int amount=ans+a[i];

        for(int j=4;j>=0;j--)
        {
            if(amount>=cost[j])
            {
                p[j]+=amount/cost[j];
                amount%=cost[j];
            }
        }
        ans=amount;
    }

    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"\n"<<ans;
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