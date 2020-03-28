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
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

//int pow[N]
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,idx;
    string a;
    set<string> grps;
    vector<string> trans;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        trans.clear();
        cin>>a;
        idx=a.size()-1;
        while(idx>=0)
        {
            if(a[idx]=='u') 
            {
                trans.pb("oo");
                idx--;
            }
            else if(a[idx]=='h')
            {
                idx=idx-1;
                while(idx>=0 && a[idx]=='k') idx--;
                trans.pb("h");
            }
            else
            {
                string str="";
                str+=a[idx];
                trans.pb(str);
                idx--;
            }
        }
        grps.insert(accumulate(r_all(trans),string("")));
    }

    cout<<grps.size();
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