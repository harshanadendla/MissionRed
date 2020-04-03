//manam entante....min value ni slice chesi....if c or m has become 0...ans anthe...leda....x+(c-x+m-x)/3 this is just same as...(c+m+x)/3
//so ans is min of c,m,avg(c,m,x)....min endukante...we slice those many....if ans comes > any of these...its imp kabatti
//anduke..min(c,m,avg)

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
    int q,team[3],idx=0,ans=0,temp;
    
    cin>>team[0];

    cin>>team[1];
    if(team[1]<team[idx]) idx=1;

    cin>>team[2];
    if(team[2]<team[idx]) idx=2;

    ans+=team[idx];

    for(int i=0;i<3;i++) team[i]-=team[idx];

    if(idx==0 || idx==1)
    {
        cout<<ans<<"\n"; 
        return;
    }

    ans+=min({ team[0],team[1],(team[0]+team[1])/3 });

    cout<<ans<<"\n";
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