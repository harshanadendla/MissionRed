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
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5;
const int mod=1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m,k,a,b;
    cin>>n>>m>>k;

    for(int i=0;i<2*k;i++)
    {
        cin>>a>>b;
    }

    string ans="";

    for(int i=1;i<n;i++) ans+="U";
    for(int i=1;i<m;i++) ans+="L";

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(i%2) ans+="L";
            else ans+="R";
        }
        if(i!=n-1) ans+="D";
    }
    
    cout<<ans.size()<<"\n"<<ans;

    return 0;
}