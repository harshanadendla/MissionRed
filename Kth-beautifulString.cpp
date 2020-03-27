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

const int N=1e5;
const int mod=1e9+7;

int sums[N];

void pre()
{
    for(int i=1;i<N;i++) sums[i]=sums[i-1]+i;
}

void solve()
{
    int n,k,id1,id2;
    cin>>n>>k;

    string str(n,'a');

    if(k==1)
    {
        id1=n-1;
        id2=n-2;
    }
    else if(2*k==n*n-n)
    {
        id1=0;
        id2=1;
    }
    else
    {
        int idx=lower_bound(sums+1,sums+1+N,k)-sums;
        id1=n-idx-1;
        id2=id1+sums[idx]-k+1;
    }
    str[id1]=str[id2]='b';

    cout<<str<<"\n";
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
    cin>>t;

    pre();

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